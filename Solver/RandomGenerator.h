#pragma once
#include "Generator.h"
#include <random>
using namespace std;
namespace miit::algebra
{
	/**
	* @brief
	*/
	class RandomGenerator : public Generator
	{
	private:
		uniform_int_distribution<int> distribution;
		mt19937 generator;
	public:
		/**
		* @brief
		* @param min
		* @param max
		*/
		RandomGenerator(const int min, const int max);
		/**
		* @brief
		*/
		int generate() override;
	};
}

