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
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");
	mu_assert_int_eq(0, dequeue_add_head(dq, 1));
	mu_assert_int_eq(1, dequeue_size(*dq));
	mu_assert_int_eq(1, dequeue_get_element(*dq, 0));
	mu_assert(!dequeue_get_element(*dq, 1), "should return NULL");

	mu_assert_int_eq(0, dequeue_add_head(dq, 2));
	mu_assert_int_eq(2, dequeue_size(*dq));

	mu_assert_int_eq(0, dequeue_add_head(dq, 3));
	mu_assert_int_eq(3, dequeue_size(*dq));

	mu_assert_int_eq(0, dequeue_add_head(dq, 4));
	mu_assert_int_eq(4, dequeue_size(*dq));

	mu_assert_int_eq(0, dequeue_add_head(dq, 5));
	mu_assert_int_eq(5, dequeue_size(*dq));
	mu_assert_int_eq(2, dequeue_get_element(*dq, 3));
	mu_assert(dequeue_is_not_empty(dq), "list should not be empty!");

	mu_assert_int_eq(5, dequeue_extract_head(dq));

	mu_assert_int_eq(4, dequeue_extract_head(dq));
	mu_assert_int_eq(3, dequeue_size(*dq));
	mu_assert_int_eq(1, dequeue_extract_tail(dq));
	mu_assert_int_eq(2, dequeue_size(*dq));

	mu_assert_int_eq(3, dequeue_extract_head(dq));
	mu_assert_int_eq(1, dequeue_size(*dq));

	mu_assert_int_eq(2, dequeue_extract_head(dq));
	mu_assert_int_eq(0, dequeue_size(*dq));
	mu_assert(!dequeue_is_not_empty(dq), "list should be empty!");
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
