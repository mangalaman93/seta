#include "minunit.h"
#include "dequeue.h"

dequeue_t *list;

void test_setup() {
	list = dequeue_create();
}

void test_teardown() {
	free(list);
}

MU_TEST(test_check) {
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
