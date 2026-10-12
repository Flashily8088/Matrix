#include "IstreamGenerator.h"
using namespace std;
miit::algebra::IstreamGenerator::IstreamGenerator(istream& in) : in(in) {};
int miit::algebra::IstreamGenerator::generate() const {
	int value = 0;
	this->in >> value;
	return value;
}