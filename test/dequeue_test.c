/*
 *  unit tests for dequeue
 *  using minunit
 *
 *  Created by Aman Mangal on 26/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include "minunit.h"
#include "dequeue.h"

dequeue_t *dq;

void test_setup() {
	dq = dequeue_create();
}

void test_teardown() {
	dequeue_destroy(dq);
}

MU_TEST(test_basic) {
	mu_assert(!dequeue_extract_head(dq), "should return NULL");
	mu_assert(!dequeue_extract_tail(dq), "should return NULL");
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");

	mu_assert_int_eq(0, dequeue_add_head(dq, 1));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(1, dequeue_size(*dq));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 0));
	mu_assert(!dequeue_get_element(*dq, 1), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_head(dq, 2));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(2, dequeue_size(*dq));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 1));
	mu_assert(!dequeue_get_element(*dq, 2), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_head(dq, 3));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(3, dequeue_size(*dq));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 2));
	mu_assert(!dequeue_get_element(*dq, 3), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_head(dq, 4));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(4, dequeue_size(*dq));
	mu_assert_int_eq(4, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 2));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 3));
	mu_assert(!dequeue_get_element(*dq, 4), "should return NULL");
	mu_assert(!dequeue_get_element(*dq, -1), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_head(dq, 5));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(5, dequeue_size(*dq));
	mu_assert_int_eq(5, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(4, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 2));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 3));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 4));
	mu_assert(!dequeue_get_element(*dq, 5), "should return NULL");

	mu_assert_int_eq(5, dequeue_extract_head(dq));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(4, dequeue_size(*dq));
	mu_assert_int_eq(4, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 2));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 3));
	mu_assert(!dequeue_get_element(*dq, 4), "should return NULL");

	mu_assert_int_eq(1, dequeue_extract_tail(dq));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(3, dequeue_size(*dq));
	mu_assert_int_eq(4, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 2));
	mu_assert(!dequeue_get_element(*dq, 3), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_tail(dq, 1));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(4, dequeue_size(*dq));
	mu_assert_int_eq(4, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 2));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 3));
	mu_assert(!dequeue_get_element(*dq, 4), "should return NULL");

	mu_assert_int_eq(4, dequeue_extract_head(dq));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(3, dequeue_size(*dq));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 1));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 2));
	mu_assert(!dequeue_get_element(*dq, 3), "should return NULL");

	mu_assert_int_eq(1, dequeue_extract_tail(dq));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(2, dequeue_size(*dq));
	mu_assert_int_eq(3, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 1));
	mu_assert(!dequeue_get_element(*dq, 2), "should return NULL");

	mu_assert_int_eq(3, dequeue_extract_head(dq));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(1, dequeue_size(*dq));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 0));
	mu_assert(!dequeue_get_element(*dq, 1), "should return NULL");

	mu_assert_int_eq(2, dequeue_extract_head(dq));
	mu_assert_int_eq(0, dequeue_size(*dq));
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");
	mu_assert(!dequeue_extract_head(dq), "should return NULL");
	mu_assert(!dequeue_extract_tail(dq), "should return NULL");
}

MU_TEST(test_large) {
	long int N = 10000000;
	for(long int i = 0; i < N; ++i)
		dequeue_add_head(dq, i);

	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N, dequeue_size(*dq));
	mu_assert_int_eq(N-500-1, dequeue_get_element(*dq, 500));

	for(long int i = 0; i < N; ++i)
		dequeue_extract_head(dq);

	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");
	mu_assert_int_eq(0, dequeue_size(*dq));
}

void * int_copy(void *i) {
	int *copy = (int *)malloc(sizeof(int));
	*copy = *((int *)i);
	return ((void *)copy);
}

MU_TEST(test_copy) {
	int N = 100;
	for(int i = 0; i < N; ++i) {
		int *temp = (int *)malloc(sizeof(int));
		*temp = i;
		dequeue_add_head(dq, temp);
	}

	dequeue_t *copy_dq = dequeue_copy(int_copy, dq);
	mu_assert(dequeue_is_not_empty(copy_dq), "list should not be empty!");
	mu_assert_int_eq(N, dequeue_size(*copy_dq));
	mu_assert(!dequeue_get_element(*copy_dq, N), "should return NULL");
	mu_assert_int_eq(N-50-1, * (int *)dequeue_get_element(*copy_dq, 50));

	dequeue_foreach(&free, copy_dq);
	dequeue_destroy(copy_dq);

	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N, dequeue_size(*dq));
	mu_assert(!dequeue_get_element(*dq, N), "should return NULL");
	mu_assert_int_eq(N-50-1, * (int *)dequeue_get_element(*dq, 50));

	dequeue_foreach(&free, dq);
}

void mydouble(void *i) {
	*((int *)i) = 2* (*((int *)i));
}

void myhalf(void *i) {
	*((int *)i) = (*((int *)i))/2;
}

void mysum(void *i, void *acc) {
	*((int *)acc) = *((int *)acc) + *((int *)i);
}

MU_TEST(test_loop) {
	// dequeue_foreach
	int N = 100;
	for(int i = 0; i < N; ++i) {
		int *temp = (int *)malloc(sizeof(int));
		*temp = i;
		dequeue_add_tail(dq, temp);
	}

	dequeue_foreach(&mydouble, dq);
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N, dequeue_size(*dq));
	mu_assert(!dequeue_get_element(*dq, N), "should return NULL");
	mu_assert_int_eq(0, * (int *)dequeue_get_element(*dq, 0));
	mu_assert_int_eq(2*50, * (int *)dequeue_get_element(*dq, 50));
	mu_assert_int_eq(2*(N-1), * (int *)dequeue_get_element(*dq, N-1));

	// dequeue_fold
	dequeue_foreach(&myhalf, dq);
	int *total = (int *)malloc(sizeof(int));
	*total = 0;
	dequeue_fold(&mysum, total, dq);
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N, dequeue_size(*dq));
	mu_assert(!dequeue_get_element(*dq, N), "should return NULL");
	mu_assert_int_eq(99*50, *total);

	free(total);
	dequeue_foreach(&free, dq);
}

bool is_negative(void *i) {
	return ((int)i < 0);
}

MU_TEST(test_accessor_and_modifier) {
	int N = 100;
	for(int i = 0; i < N; ++i)
		dequeue_add_tail(dq, i);

	// dequeue_remove_element_by_value
	mu_assert_int_eq(0, dequeue_remove_element_by_value(dq, 5));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N-1, dequeue_size(*dq));
	mu_assert_int_eq(6, dequeue_get_element(*dq, 5));

	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, N));
	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 5));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(N-1, dequeue_size(*dq));
	mu_assert_int_eq(6, dequeue_get_element(*dq, 5));

	for(int i = 0; i < N; ++i)
		dequeue_remove_element_by_value(dq, i);
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");

	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 10));
	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 1));

	dequeue_add_head(dq, 90);
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");
	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 10));
	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 1));
	mu_assert_int_eq(0, dequeue_remove_element_by_value(dq, 90));
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");
	mu_assert_int_eq(-1, dequeue_remove_element_by_value(dq, 90));

	// dequeue_set_element
	mu_assert_int_eq(-1, dequeue_set_element(dq, 0, 10));
	dequeue_add_tail(dq, 90);
	mu_assert_int_eq(0, dequeue_set_element(dq, 0, 10));
	mu_assert_int_eq(10, dequeue_get_element(*dq, 0));
	mu_assert_int_eq(10, dequeue_get_last(*dq));
	mu_assert(!dequeue_get_element(*dq, 1), "should return NULL");

	for(int i = 0; i < N; ++i)
		dequeue_add_tail(dq, i);

	mu_assert_int_eq(0, dequeue_set_element(dq, 50, 10));
	mu_assert_int_eq(10, dequeue_get_element(*dq, 50));
	mu_assert(!dequeue_get_element(*dq, -1), "should return NULL");

	for(int i = 0; i < N+1; ++i)
		dequeue_extract_head(dq);
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");

	// dequeue_get_first_matching_fun, dequeue_get_last_matching_fun
	mu_assert(!dequeue_get_first_matching_fun(&is_negative, dq), "should return NULL");
	mu_assert(!dequeue_get_last_matching_fun(&is_negative, dq), "should return NULL");

	for(int i = 0; i < N; ++i)
		dequeue_add_tail(dq, i);
	mu_assert_int_eq(0, dequeue_set_element(dq, 10, -1));
	mu_assert_int_eq(0, dequeue_set_element(dq, 40, -2));
	mu_assert_int_eq(0, dequeue_set_element(dq, 67, -3));
	mu_assert_int_eq(0, dequeue_set_element(dq, 78, -4));

	mu_assert_int_eq(-1, dequeue_get_first_matching_fun(&is_negative, dq));
	mu_assert_int_eq(-4, dequeue_get_last_matching_fun(&is_negative, dq));
}

MU_TEST(test_iterator) {
	dequeue_iterator_t iterator = dequeue_get_iterator(dq);
	while (dequeue_iterator_has_more(&iterator)) {
		mu_fail("should not reach here!");
	}

	int N = 100;
	for(int i = 0; i < N; ++i)
		dequeue_add_tail(dq, i);

	iterator = dequeue_get_iterator(dq);
	int i = 0;
	while (dequeue_iterator_has_more(&iterator)) {
		int cur_val = (int)dequeue_iterator_get_next(&iterator);
		mu_assert_int_eq(i, cur_val);
		i++;
	}
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_basic);
	MU_RUN_TEST(test_large);
	MU_RUN_TEST(test_copy);
	MU_RUN_TEST(test_loop);
	MU_RUN_TEST(test_accessor_and_modifier);
	MU_RUN_TEST(test_iterator);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
