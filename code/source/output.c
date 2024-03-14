/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xmock/output.h"
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
