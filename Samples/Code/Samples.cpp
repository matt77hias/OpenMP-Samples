//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

// Pi_Parallel, Pi_ParallelWithoutReduction, Pi_Sequential
#include "Pi.hpp"

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------

// cout
#include <iostream>
// numeric_limits
#include <limits>

//-----------------------------------------------------------------------------
// Declarations
//-----------------------------------------------------------------------------
int main()
{
	constexpr int a[] = { 100, 1000, 10000 };

	std::cout.precision(std::numeric_limits< double >::max_digits10);

	for (int step_count : a)
	{
		std::cout << "pi: " << Pi_Sequential(step_count) << std::endl;
	}
	for (int step_count : a)
	{
		std::cout << "pi: " << Pi_Parallel(step_count) << std::endl;
	}
	for (int step_count : a)
	{
		std::cout << "pi: " << Pi_ParallelWithoutReduction(step_count) << std::endl;
	}

	return 0;
}