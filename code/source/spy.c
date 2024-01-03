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
#include "fossil/xmock/spy.h"

// Function to initialize the spy structure
XMockSpy* xmock_spy_create(void) {
    XMockSpy* spy = (XMockSpy*)malloc(sizeof(XMockSpy));
    if (spy == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for XMockSpy\n");
        exit(EXIT_FAILURE);
    } // end if

    spy->callCount = 0;
    return spy;
} // end of func

// Function to record a function call in the spy structure
void xmock_spy_record_call(XMockSpy* spy) {
    if (spy == NULL) {
        fprintf(stderr, "Error: NULL spy provided to xmock_spy_record_call\n");
        exit(EXIT_FAILURE);
    } // end if

    spy->callCount++;
} // end of func

// Function to get the call count from the spy structure
int xmock_spy_get_call_count(XMockSpy* spy) {
    if (spy == NULL) {
        fprintf(stderr, "Error: NULL spy provided to xmock_spy_get_call_count\n");
        exit(EXIT_FAILURE);
    } // end if

    return spy->callCount;
} // end of func

// Function to clean up and free the memory used by the spy structure
void xmock_spy_erase(XMockSpy* spy) {
    free(spy);
} // end of func
