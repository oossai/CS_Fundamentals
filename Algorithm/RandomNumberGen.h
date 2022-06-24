#pragma once
#include <random>

auto CreatePseudoRandomNumberGen(size_t lowerBound, size_t upperBound)
{
	std::random_device seeder;
	std::default_random_engine rng{seeder()};
	std::uniform_int_distribution distribution{lowerBound, upperBound};
	return std::bind(distribution, rng);
}
