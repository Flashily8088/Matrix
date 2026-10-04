#include "ConstantGenerator.h"

miit::algebra::ConstantGenerator::ConstantGenerator(int value) : constant_value(value) {}

int miit::algebra::ConstantGenerator::generate()
{
	return constant_value;
}
