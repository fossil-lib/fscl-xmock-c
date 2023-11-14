/*  ----------------------------------------------------------------------------
    File: behavior.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

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
#include "trilobite/xmock/behavior.h"

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
void xmock_behavior_destroy(XMockBehavior* behavior) {
    free(behavior);
} // end of func
