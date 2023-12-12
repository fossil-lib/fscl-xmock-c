/*  ----------------------------------------------------------------------------
    File: fake.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

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
#include "trilobite/xmock/fake.h"

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
