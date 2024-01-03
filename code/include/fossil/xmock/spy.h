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
#ifndef FSCL_XMOCK_SPY_H
#define FSCL_XMOCK_SPY_H

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

// Structure to store information about function calls
typedef struct {
    int callCount;
} XMockSpy;

/**
 * @brief Creates a new instance of XMockSpy.
 *
 * This function allocates memory for a new XMockSpy and initializes its fields.
 *
 * @return A pointer to the newly created XMockSpy instance.
 */
XMockSpy* xmock_spy_create(void);

/**
 * @brief Records a call in the XMockSpy.
 *
 * This function is used to record the occurrence of a function call in the spy.
 * It increments the call count of the spy, providing a way to track the number of calls.
 *
 * @param spy A pointer to the XMockSpy in which to record a call.
 */
void xmock_spy_record_call(XMockSpy* spy);

/**
 * @brief Gets the call count from the XMockSpy.
 *
 * This function retrieves the total number of recorded calls in the XMockSpy.
 *
 * @param spy A pointer to the XMockSpy from which to retrieve the call count.
 * @return The number of calls recorded in the XMockSpy.
 */
int xmock_spy_get_call_count(XMockSpy* spy);

/**
 * @brief Destroys an instance of XMockSpy.
 *
 * This function frees the memory allocated for the XMockSpy instance.
 *
 * @param spy A pointer to the XMockSpy instance to destroy.
 */
void xmock_spy_erase(XMockSpy* spy);

#ifdef __cplusplus
}
#endif

#endif