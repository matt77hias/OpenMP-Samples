#include "samples.hpp"

inline double pi_sequential(int nb_blocks = 1000) {

	const double dx = 1.0 / nb_blocks;

	double integral = 0.0;
	for (int i = 0; i < nb_blocks; ++i) {
		const double a = i * dx;
		const double b = a + dx;
		const double fa = 1.0 / (1.0 + a*a);
		const double fb = 1.0 / (1.0 + b*b);
		integral += 0.5 * dx * (fa + fb);
	}

	return 4.0 * integral;
}

inline double pi_parallel(int nb_blocks = 1000) {

	const double dx = 1.0 / nb_blocks;

	double integral = 0.0;
#pragma omp parallel for schedule(static) default(none) firstprivate(nb_blocks) reduction(+:integral)
	for (int i = 0; i < nb_blocks; ++i) {
		const double a = i * dx;
		const double b = a + dx;
		const double fa = 1.0 / (1.0 + a*a);
		const double fb = 1.0 / (1.0 + b*b);
		integral += 0.5 * dx * (fa + fb);
	}

	return 4.0 * integral;
}

int main() {

	printf("pi: %lf\n", pi_parallel(1000));

	return 0;
}



