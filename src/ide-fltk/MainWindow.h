// -*- c-file-style: "java" -*-
// $Id: MainWindow.h,v 1.15 2005-03-29 23:45:07 zeeb90au Exp $
// This file is part of SmallBASIC
//
// Copyright(C) 2001-2003 Chris Warren-Smith. Gawler, South Australia
// cwarrens@twpo.com.au
//
// This program is distributed under the terms of the GPL v2.0 or later
// Download the GNU Public License (GPL) from www.gnu.org
// 

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <fltk/Window.h>
#include <fltk/TabGroup.h>

#include "Fl_Ansi_Window.h"
#include "EditorWindow.h"

#define C_LINKAGE_BEGIN extern "C" {
#define C_LINKAGE_END }

#ifndef max
#define max(a,b) ((a<b) ? (b) : (a))
#endif
#ifndef min
#define min(a,b) ((a>b) ? (b) : (a))
#endif

void trace(const char *format, ...);

struct MainWindow : public Window {
    MainWindow(int w, int h);
    ~MainWindow();

    int handle(int e);
    bool isBreakExec(void);
    bool isModal();
    bool isEdit();
    void setModal(bool modal);
    void setBreak();
    void resetPen();
    void execLink(const char* file);

    int penDownX;
    int penDownY;
    int penState;
    bool isTurbo;
    bool modalLoop;

    // main output
    AnsiWindow *out;
    EditorWindow* editWnd;

    // tabs
    TabGroup* tabGroup;
    Group* editGroup;
    Group* outputGroup;
    Group* browseGroup;

    // status bar
    Widget* fileStatus;
    Widget* rowStatus;
    Widget* colStatus;
    Widget* runStatus;
    Widget* modStatus;
};

#endif
