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
#ifndef FSCL_XMOCK_STUB_H
#define FSCL_XMOCK_STUB_H

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

// Structure to represent a stub
typedef struct {
    int predefinedResponse;
} XMockStub;

/**
 * @brief Creates a new instance of XMockStub.
 *
 * This function allocates memory for a new XMockStub and initializes its fields.
 *
 * @return A pointer to the newly created XMockStub instance.
 */
XMockStub* xmock_stub_create(void);

/**
 * @brief Sets the predefined response for the given XMockStub.
 *
 * This function allows you to specify the response that the stub should provide when called.
 *
 * @param stub      A pointer to the XMockStub for which to set the response.
 * @param response  The predefined response to set for the stub.
 */
void xmock_stub_set_response(XMockStub* stub, int response);

/**
 * @brief Gets the predefined response from the given XMockStub.
 *
 * This function retrieves the predefined response that was set for the stub.
 *
 * @param stub  A pointer to the XMockStub from which to retrieve the response.
 * @return The predefined response set for the stub.
 */
int xmock_stub_get_response(XMockStub* stub);

/**
 * @brief Destroys an instance of XMockStub.
 *
 * This function frees the memory allocated for the XMockStub instance.
 *
 * @param stub  A pointer to the XMockStub instance to destroy.
 */
void xmock_stub_erase(XMockStub* stub);

#ifdef __cplusplus
}
#endif

#endif