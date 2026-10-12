#include "ConstantGenerator.h"

miit::algebra::ConstantGenerator::ConstantGenerator(int value) : constant_value(value) {}

int miit::algebra::ConstantGenerator::generate() const
{
	return constant_value;
}
