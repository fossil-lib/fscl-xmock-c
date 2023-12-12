/*  ----------------------------------------------------------------------------
    File: output.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xmock/output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    HANDLE original_stdout;
#else
    #include <unistd.h>
    #include <fcntl.h>
    FILE* original_stdout;
#endif

static char captured_output[4096];
static int output_capture_enabled = 0;

void xmock_io_setup(void) {
    #ifdef _WIN32
        original_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    #else
        original_stdout = stdout;
    #endif
} // end of func

void xmock_io_teardown(void) {
    #ifdef _WIN32
        SetStdHandle(STD_OUTPUT_HANDLE, original_stdout);
    #else
        // No teardown needed for popen-based approach
    #endif
} // end of func

void xmock_io_capture_output(void) {
    memset(captured_output, 0, sizeof(captured_output));
    output_capture_enabled = 1;

    #ifdef _WIN32
        HANDLE hCaptureFile = CreateFile("CONOUT$", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        SetStdHandle(STD_OUTPUT_HANDLE, hCaptureFile);
    #else
        FILE* captureFile = fopen("output_capture.txt", "w");
        if (captureFile != NULL) {
            original_stdout = stdout;  // Save the original stdout
            stdout = captureFile;  // Redirect stdout to the file
        }
    #endif
} // end of func

const char* xmock_io_get_output(void) {
    output_capture_enabled = 0;

    #ifdef _WIN32
        // Read from the captured file
        FILE* captureFile = fopen("output_capture.txt", "r");
        if (captureFile != NULL) {
            fread(captured_output, 1, sizeof(captured_output), captureFile);
            fclose(captureFile);
        }
    #else
        // No additional actions needed for popen-based approach
    #endif

    return captured_output;
} // end of func

void xmock_io_restore_output(void) {
    #ifdef _WIN32
        SetStdHandle(STD_OUTPUT_HANDLE, original_stdout);
    #else
        stdout = original_stdout;  // Restore stdout to the original value
    #endif
} // end of func
