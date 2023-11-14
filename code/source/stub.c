/*  ----------------------------------------------------------------------------
    File: stub.c

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
#include "trilobite/xmock/stub.h"

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
void xmock_stub_destroy(XMockStub* stub) {
    free(stub);
} // end of func
