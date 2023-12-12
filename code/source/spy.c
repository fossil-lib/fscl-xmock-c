/*  ----------------------------------------------------------------------------
    File: spy.c

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
#include "trilobite/xmock/spy.h"

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
