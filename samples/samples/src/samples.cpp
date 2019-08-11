//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

// pi_parallel, pi_parallel_no_reduction, pi_sequential
#include "pi.hpp"

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------

// cout
#include <iostream>
// numeric_limits
#include <limits>

int main()
{
	constexpr int a[] = { 100, 1000, 10000 };

	std::cout.precision(std::numeric_limits< double >::max_digits10);

	for (int step_count : a)
	{
		std::cout << "pi: " << pi_sequential(step_count) << std::endl;
	}
	for (int step_count : a)
	{
		std::cout << "pi: " << pi_parallel(step_count) << std::endl;
	}
	for (int step_count : a)
	{
		std::cout << "pi: " << pi_parallel_no_reduction(step_count) << std::endl;
	}

	return 0;
}
