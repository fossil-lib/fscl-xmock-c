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
#ifndef FSCL_XMOCK_OUTPUT_H
#define FSCL_XMOCK_OUTPUT_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstdio>
#else
#include <stdlib.h>
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _WIN32
    // Windows headers
    #include <windows.h>
#else
    // POSIX headers
    #include <unistd.h>
#endif

/**
 * @brief Set up the xmock_io library.
 */
void xmock_io_setup(void);

/**
 * @brief Tear down the xmock_io library.
 */
void xmock_io_teardown(void);

/**
 * @brief Capture console output for mocking purposes.
 */
void xmock_io_capture_output(void);

/**
 * @brief Get the captured console output.
 * 
 * @return A pointer to the captured console output.
 */
const char* xmock_io_get_output(void);

/**
 * @brief Restore the original console output.
 */
void xmock_io_restore_output(void);

//
//
//

// Function to set the mock input function
void xmock_io_set_input(char *(*input_func)())'

// Function to mock input
char *xmock_io_get_input();

// Mocking scanf function
int xmock_io_scanf(const char *format, ...);

// Mocking gets function
char *xmock_io_gets(char *str);

// Mocking fgets function
char *xmock_io_fgets(char *str, int size, FILE *stream);

#ifdef __cplusplus
}
#endif

#endif
