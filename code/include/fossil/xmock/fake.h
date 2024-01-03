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
#ifndef FSCL_XMOCK_FAKE_H
#define FSCL_XMOCK_FAKE_H

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

// Structure to store information about fake function calls
typedef struct {
    int callCount;
    int returnValue;
} XMockFake;

/**
 * @brief Creates a new instance of XMockFake.
 *
 * This function allocates memory for a new XMockFake and initializes its fields.
 *
 * @return A pointer to the newly created XMockFake instance.
 */
XMockFake* xmock_fake_create(void);

/**
 * @brief Sets the return value for the fake function.
 *
 * This function allows you to specify the return value that the fake function should provide.
 *
 * @param fake   A pointer to the XMockFake for which to set the return value.
 * @param value  The return value to set for the fake function.
 */
void xmock_fake_set_return_value(XMockFake* fake, int value);

/**
 * @brief Records a call in the XMockFake.
 *
 * This function is used to record the occurrence of a function call in the fake.
 * It increments the call count of the fake, providing a way to track the number of calls.
 *
 * @param fake A pointer to the XMockFake in which to record a call.
 */
void xmock_fake_record_call(XMockFake* fake);

/**
 * @brief Gets the call count from the XMockFake.
 *
 * This function retrieves the total number of recorded calls in the XMockFake.
 *
 * @param fake A pointer to the XMockFake from which to retrieve the call count.
 * @return The number of calls recorded in the XMockFake.
 */
int xmock_fake_get_call_count(XMockFake* fake);

/**
 * @brief Gets the return value of the fake function.
 *
 * This function retrieves the return value that was set for the fake function.
 *
 * @param fake A pointer to the XMockFake from which to retrieve the return value.
 * @return The return value set for the fake function.
 */
int xmock_fake_get_return_value(XMockFake* fake);

/**
 * @brief Destroys an instance of XMockFake.
 *
 * This function frees the memory allocated for the XMockFake instance.
 *
 * @param fake A pointer to the XMockFake instance to destroy.
 */
void xmock_fake_erase(XMockFake* fake);

#ifdef __cplusplus
}
#endif

#endif