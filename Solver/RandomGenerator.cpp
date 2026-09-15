#include "RandomGenerator.h"
using namespace std;
miit::algebra::RandomGenerator::RandomGenerator(const int min, const int max) {
	this->generator = mt19937(random_device{}());
	this->distribution = uniform_int_distribution<int>(min, max);
}
int miit::algebra::RandomGenerator::generate() {
	return this->distribution(this->generator);
}

