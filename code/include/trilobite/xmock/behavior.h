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
#ifndef TRILOBITE_XMOCK_BEHAVIOR_H
#define TRILOBITE_XMOCK_BEHAVIOR_H

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

// Structure to represent behavior verification
typedef struct {
    // Fields to store information about behavior
    int expectedCallCount;
    int actualCallCount;
} XMockBehavior;

/**
 * @brief Creates a new instance of XMockBehavior.
 *
 * This function allocates memory for a new XMockBehavior and initializes its fields.
 *
 * @return A pointer to the newly created XMockBehavior instance.
 */
XMockBehavior* xmock_behavior_create(void);

/**
 * @brief Sets the expected call count for behavior verification.
 *
 * This function allows you to specify the expected number of calls that should occur.
 *
 * @param behavior  A pointer to the XMockBehavior for which to set the expected call count.
 * @param count     The expected number of calls for behavior verification.
 */
void xmock_behavior_expect_call_count(XMockBehavior* behavior, int count);

/**
 * @brief Records a call and verifies behavior.
 *
 * This function is used to record the occurrence of a function call in the behavior verification.
 * It increments the actual call count and performs behavior verification against the expected call count.
 *
 * @param behavior  A pointer to the XMockBehavior in which to record a call and verify behavior.
 */
void xmock_behavior_record_call(XMockBehavior* behavior);

/**
 * @brief Verifies that the expected calls match the actual calls.
 *
 * This function compares the expected call count with the actual call count and reports any discrepancies.
 *
 * @param behavior  A pointer to the XMockBehavior for which to verify behavior.
 */
void xmock_behavior_verify(XMockBehavior* behavior);

/**
 * @brief Destroys an instance of XMockBehavior.
 *
 * This function frees the memory allocated for the XMockBehavior instance.
 *
 * @param behavior  A pointer to the XMockBehavior instance to destroy.
 */
void xmock_behavior_erase(XMockBehavior* behavior);

#ifdef __cplusplus
}
#endif

#endif