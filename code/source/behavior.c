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
#include "fossil/xmock/behavior.h"

// Function to create a new behavior verification instance
XMockBehavior* xmock_behavior_create(void) {
    XMockBehavior* behavior = (XMockBehavior*)malloc(sizeof(XMockBehavior));
    if (behavior == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for XMockBehavior\n");
        exit(EXIT_FAILURE);
    } // end if

    // Initialize fields as needed
    behavior->expectedCallCount = 0;
    behavior->actualCallCount = 0;

    return behavior;
} // end of func

// Function to set the expected call count for behavior verification
void xmock_behavior_expect_call_count(XMockBehavior* behavior, int count) {
    if (behavior == NULL) {
        fprintf(stderr, "Error: NULL behavior provided to xmock_behavior_expect_call_count\n");
        exit(EXIT_FAILURE);
    } // end if

    behavior->expectedCallCount = count;
} // end of func

// Function to record a call and verify behavior
void xmock_behavior_record_call(XMockBehavior* behavior) {
    if (behavior == NULL) {
        fprintf(stderr, "Error: NULL behavior provided to xmock_behavior_record_call\n");
        exit(EXIT_FAILURE);
    } // end if

    behavior->actualCallCount++;
} // end of func

// Function to verify that the expected calls match the actual calls
void xmock_behavior_verify(XMockBehavior* behavior) {
    if (behavior == NULL) {
        fprintf(stderr, "Error: NULL behavior provided to xmock_behavior_verify\n");
        exit(EXIT_FAILURE);
    } // end if

    if (behavior->expectedCallCount != behavior->actualCallCount) {
        fprintf(stderr, "Behavior verification failed: Expected %d calls, but got %d calls\n",
                behavior->expectedCallCount, behavior->actualCallCount);
        exit(EXIT_FAILURE);
    } // end if

    // You may add more detailed behavior verification logic here

    // Reset the actual call count for subsequent tests
    behavior->actualCallCount = 0;
} // end of func

// Function to clean up and free the memory used by behavior verification
void xmock_behavior_erase(XMockBehavior* behavior) {
    free(behavior);
} // end of func
