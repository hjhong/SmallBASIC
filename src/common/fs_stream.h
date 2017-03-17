// This file is part of SmallBASIC
//
// stream-files, driver 
//
// This program is distributed under the terms of the GPL v2.0 or later
// Download the GNU Public License (GPL) from www.gnu.org
//
// Copyright(C) 2000 Nicholas Christopoulos

#if !defined(_sbfs_stream_h)
#define _sbfs_stream_h

#include "common/sys.h"
#include "common/device.h"

int stream_open(dev_file_t *f);
int stream_close(dev_file_t *f);
int stream_write(dev_file_t *f, byte *data, uint32_t size);
int stream_read(dev_file_t *f, byte *data, uint32_t size);
uint32_t stream_tell(dev_file_t *f);
uint32_t stream_length(dev_file_t *f);
uint32_t stream_seek(dev_file_t *f, uint32_t offset);
int stream_eof(dev_file_t *f);

#endif
