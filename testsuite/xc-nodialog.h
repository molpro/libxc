/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Fail loudly instead of waiting for someone to click OK.

  On Windows a Debug build that hits a CRT assertion, an /RTC1 runtime check
  or an access violation raises a modal dialog. Under CI there is nobody to
  dismiss it, so the process blocks until the job is killed: a test that runs
  in 0.00 s on Linux sat for 54 minutes on an AppVeyor Debug image, with no
  output to say why.

  Route those reports to stderr and let the process die with a status the
  harness can see. Everything here is a no-op off Windows.
*/

#ifndef XC_NODIALOG_H
#define XC_NODIALOG_H

#if defined(_WIN32)

#include <windows.h>
#if defined(_MSC_VER)
#include <crtdbg.h>
#include <stdlib.h>
#endif

static void xc_test_no_dialogs(void) {
  /* No "program has stopped working" box, and no dialog from a failed
     hard-disk/critical error. */
  SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX
               | SEM_NOOPENFILEERRORBOX);
#if defined(_MSC_VER)
  /* abort() must not raise its own dialog either. */
  _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
  /* Send assertion and runtime-check reports to stderr rather than a window. */
  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
  _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
#endif
}

#else

static void xc_test_no_dialogs(void) {}

#endif

#endif /* XC_NODIALOG_H */
