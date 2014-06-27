/*
 *  unit tests for seta API
 *  using minunit
 *
 *  Created by Aman Mangal on 27/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include "minunit.h"
#include "seta.h"

void test_setup() {
}

void test_teardown() {
}

void entry(seta_context_t context) {
}

MU_TEST(test_seta_enable_info) {
	// doesn't return anything, just modifies global variables
}

MU_TEST(test_seta_enable_graph) {
	// doesn't return anything, just modifies global variables
}

MU_TEST(test_seta_arg_name_list) {
}

MU_TEST(test_seta_start) {
	int num_processors = -1;
	mu_assert_int_eq(-1, seta_start(&entry, num_processors));

	num_processors = 0;
	mu_assert_int_eq(-1, seta_start(&entry, num_processors));
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_seta_enable_info);
	MU_RUN_TEST(test_seta_enable_graph);
	MU_RUN_TEST(test_seta_start);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
