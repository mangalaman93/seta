/*
 *  unit tests for lists
 *  using minunit
 *
 *  Created by Aman Mangal on 27/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include "minunit.h"
#include "lists.h"

void test_setup() {
}

void test_teardown() {
}

MU_TEST(test_basic) {
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_basic);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
