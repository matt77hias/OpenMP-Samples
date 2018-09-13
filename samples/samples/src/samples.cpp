//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "pi.hpp"

#pragma endregion
//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------
#pragma region

#include <iostream>
#include <limits>

#pragma endregion

int main() {
	constexpr int a[] = { 100, 1000, 10000 };

	std::cout.precision(std::numeric_limits< double >::max_digits10);

	for (int nb_steps : a) {
		std::cout << "pi: " << pi_sequential(nb_steps) << std::endl;
	}
	for (int nb_steps : a) {
		std::cout << "pi: " << pi_parallel(nb_steps) << std::endl;
	}
	for (int nb_steps : a) {
		std::cout << "pi: " << pi_parallel_no_reduction(nb_steps) << std::endl;
	}

	return 0;
}
