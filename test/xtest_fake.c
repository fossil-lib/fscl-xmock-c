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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xmock/fake.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(xmock_fake_create_object) {
    XMockFake* fake = xmock_fake_create();
    TEST_ASSERT_NOT_CNULLPTR(fake);
    xmock_fake_erase(fake);
}

XTEST_CASE(xmock_fake_set_return_value_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_set_return_value(fake, 42);
    TEST_ASSERT_EQUAL_INT(42, xmock_fake_get_return_value(fake));
    xmock_fake_erase(fake);
}

XTEST_CASE(xmock_fake_record_call_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_record_call(fake);
    TEST_ASSERT_EQUAL_INT(1, xmock_fake_get_call_count(fake));
    xmock_fake_erase(fake);
}

XTEST_CASE(xmock_fake_get_call_count_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_record_call(fake);
    xmock_fake_record_call(fake);
    TEST_ASSERT_EQUAL_INT(2, xmock_fake_get_call_count(fake));
    xmock_fake_erase(fake);
}

XTEST_CASE(xmock_fake_get_return_value_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_set_return_value(fake, 42);
    TEST_ASSERT_EQUAL_INT(42, xmock_fake_get_return_value(fake));
    xmock_fake_erase(fake);
}

XTEST_CASE(xmock_fake_erase_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_erase(fake);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_fakes_group) {
    XTEST_RUN_UNIT(xmock_fake_create_object);
    XTEST_RUN_UNIT(xmock_fake_set_return_value_object);
    XTEST_RUN_UNIT(xmock_fake_record_call_object);
    XTEST_RUN_UNIT(xmock_fake_get_call_count_object);
    XTEST_RUN_UNIT(xmock_fake_get_return_value_object);
    XTEST_RUN_UNIT(xmock_fake_erase_object);
} // end of fixture
