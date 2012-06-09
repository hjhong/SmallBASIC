// This file is part of SmallBASIC
//
// Copyright(C) 2001-2012 Chris Warren-Smith.
//
// This program is distributed under the terms of the GPL v2.0 or later
// Download the GNU Public License (GPL) from www.gnu.org
//

#include <MAUtil/Environment.h>
#include <MAUtil/String.h>

#include "config.h"
#include "common/sbapp.h"
#include "common/sys.h"
#include "common/smbas.h"
#include "common/osd.h"
#include "common/device.h"
#include "common/blib_ui.h"

#include "platform/mosync/ansiwidget.h"

using namespace MAUtil;

#define EVT_MAX_BURN_TIME (CLOCKS_PER_SEC / 4)
#define EVT_PAUSE_TIME 5
#define EVT_CHECK_EVERY ((50 * CLOCKS_PER_SEC) / 1000)
#define PEN_OFF   0             // pen mode disabled
#define PEN_ON    2             // pen mode active

struct Controller : public Environment, HyperlinkListener {
  Controller();
  virtual ~Controller();

  const char *getLoadPath();
  int getPen(int code);
  bool hasGUI();
  int handleEvents(int waitFlag);
  void modalLoop();
  void pause(int ms);
  MAEvent processEvents(int ms, int untilType);
  char *readConnection(const char *url);

  bool isExit() { return runMode == exit_state; }
  bool isModal() { return runMode == modal_state; }
  bool isRunning() { return runMode == run_state || runMode == modal_state; }
  void setPenMode(int b) { penMode = (b ? PEN_ON : PEN_OFF); }
  void setRunning();

  AnsiWidget *output;

private:
  void fireEvent(MAEvent &event);
  void handleKey(int key);
  void linkClicked(const char *url);

  enum ExecState {
    init_state,
    run_state,
    restart_state,
    modal_state,
    break_state,
    conn_state,
    exit_state
  };

  ExecState runMode;
  clock_t lastEventTime;
  dword eventsPerTick;
  int penMode;
  int penDownX;
  int penDownY;
  String loadPath;
};
