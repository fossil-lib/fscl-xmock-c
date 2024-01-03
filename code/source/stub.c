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
#include "fossil/xmock/stub.h"

// Function to create a new stub
XMockStub* xmock_stub_create(void) {
    XMockStub* stub = (XMockStub*)malloc(sizeof(XMockStub));
    if (stub == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for XMockStub\n");
        exit(EXIT_FAILURE);
    } // end if

    // Set default predefined response for the stub
    stub->predefinedResponse = 0;

    return stub;
} // end of func

// Function to set the predefined response for the stub
void xmock_stub_set_response(XMockStub* stub, int response) {
    if (stub == NULL) {
        fprintf(stderr, "Error: NULL stub provided to xmock_stub_set_response\n");
        exit(EXIT_FAILURE);
    } // end if

    stub->predefinedResponse = response;
} // end of func

// Function to get the predefined response from the stub
int xmock_stub_get_response(XMockStub* stub) {
    if (stub == NULL) {
        fprintf(stderr, "Error: NULL stub provided to xmock_stub_get_response\n");
        exit(EXIT_FAILURE);
    } // end if

    return stub->predefinedResponse;
} // end of func

// Function to clean up and free the memory used by the stub
void xmock_stub_erase(XMockStub* stub) {
    free(stub);
} // end of func
