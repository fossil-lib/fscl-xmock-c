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
#include "fossil/xmock/fake.h"

// Function to create a new fake function
XMockFake* xmock_fake_create(void) {
    XMockFake* fake = (XMockFake*)malloc(sizeof(XMockFake));
    if (fake == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for XMockFake\n");
        exit(EXIT_FAILURE);
    } // end if

    fake->callCount = 0;
    fake->returnValue = 0; // Set a default return value
    return fake;
} // end of func

// Function to set the return value for the fake function
void xmock_fake_set_return_value(XMockFake* fake, int value) {
    if (fake == NULL) {
        fprintf(stderr, "Error: NULL fake provided to xmock_fake_set_return_value\n");
        exit(EXIT_FAILURE);
    } // end if

    fake->returnValue = value;
} // end of func

// Function to record a fake function call
void xmock_fake_record_call(XMockFake* fake) {
    if (fake == NULL) {
        fprintf(stderr, "Error: NULL fake provided to xmock_fake_record_call\n");
        exit(EXIT_FAILURE);
    } // end if

    fake->callCount++;
} // end of func

// Function to get the call count from the fake function
int xmock_fake_get_call_count(XMockFake* fake) {
    if (fake == NULL) {
        fprintf(stderr, "Error: NULL fake provided to xmock_fake_get_call_count\n");
        exit(EXIT_FAILURE);
    } // end if

    return fake->callCount;
} // end of func

// Function to get the return value of the fake function
int xmock_fake_get_return_value(XMockFake* fake) {
    if (fake == NULL) {
        fprintf(stderr, "Error: NULL fake provided to xmock_fake_get_return_value\n");
        exit(EXIT_FAILURE);
    } // end if

    return fake->returnValue;
} // end of func

// Function to clean up and free the memory used by the fake function
void xmock_fake_erase(XMockFake* fake) {
    free(fake);
} // end of func
