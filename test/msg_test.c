/*
 *  unit tests for msg
 *  using minunit
 *
 *  Created by Aman Mangal on 27/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include "minunit.h"
#include "msg.h"

static msg_t mt;

void test_setup() {
	mt = msg_new();
}

void test_teardown() {
	msg_destroy(mt);
}

MU_TEST(test_basic) {
	msg_destroy(mt);
	mt = msg_new_from_str("hi, what's up?");
	mu_assert_int_eq('h', *(mt));
	mu_assert_int_eq('i', *(mt+1));
	mu_assert_int_eq(',', *(mt+2));
	mu_assert_int_eq(' ', *(mt+3));
	mu_assert_int_eq('w', *(mt+4));
	mu_assert_int_eq('h', *(mt+5));
	mu_assert_int_eq('a', *(mt+6));
	mu_assert_int_eq('t', *(mt+7));
	mu_assert_int_eq('\'', *(mt+8));
	mu_assert_int_eq('s', *(mt+9));
	mu_assert_int_eq(' ', *(mt+10));
	mu_assert_int_eq('u', *(mt+11));
	mu_assert_int_eq('p', *(mt+12));
	mu_assert_int_eq('?', *(mt+13));
	mu_assert_int_eq('\0', *(mt+14));

	msg_destroy(mt);
	mt = msg_new_from_int(100);
	mu_assert_int_eq('1', *(mt));
	mu_assert_int_eq('0', *(mt+1));
	mu_assert_int_eq('0', *(mt+2));
	mu_assert_int_eq('\0', *(mt+3));
}

MU_TEST(test_concat) {
	msg_cat(&mt, "hi! ");
	mu_assert_int_eq('h', *(mt));
	mu_assert_int_eq('i', *(mt+1));
	mu_assert_int_eq('!', *(mt+2));
	mu_assert_int_eq(' ', *(mt+3));
	mu_assert_int_eq('\0', *(mt+4));

	msg_ncat(&mt, "what are you doing?", 10);
	mu_assert_int_eq('h', *(mt));
	mu_assert_int_eq('i', *(mt+1));
	mu_assert_int_eq('!', *(mt+2));
	mu_assert_int_eq(' ', *(mt+3));
	mu_assert_int_eq('w', *(mt+4));
	mu_assert_int_eq('h', *(mt+5));
	mu_assert_int_eq('a', *(mt+6));
	mu_assert_int_eq('t', *(mt+7));
	mu_assert_int_eq(' ', *(mt+8));
	mu_assert_int_eq('a', *(mt+9));
	mu_assert_int_eq('r', *(mt+10));
	mu_assert_int_eq('e', *(mt+11));
	mu_assert_int_eq(' ', *(mt+12));
	mu_assert_int_eq('y', *(mt+13));
	mu_assert_int_eq('\0', *(mt+14));
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_basic);
	MU_RUN_TEST(test_concat);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
