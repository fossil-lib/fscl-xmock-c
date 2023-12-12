/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XMOCK_STUB_H
#define TRILOBITE_XMOCK_STUB_H

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