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
#ifndef FSCL_XMOCK_BEHAVIOR_H
#define FSCL_XMOCK_BEHAVIOR_H

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