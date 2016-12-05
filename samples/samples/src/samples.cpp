#include "samples.hpp"
#include "pi.hpp"

int main() {

	printf("pi: %lf\n", pi_sequential(100));
	printf("pi: %lf\n", pi_sequential(1000));
	printf("pi: %lf\n", pi_sequential(10000));

	printf("pi: %lf\n", pi_parallel(100));
	printf("pi: %lf\n", pi_parallel(1000));
	printf("pi: %lf\n", pi_parallel(10000));

	printf("pi: %lf\n", pi_parallel_no_reduction(100));
	printf("pi: %lf\n", pi_parallel_no_reduction(1000));
	printf("pi: %lf\n", pi_parallel_no_reduction(10000));

	return 0;
}