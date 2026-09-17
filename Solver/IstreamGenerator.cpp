#include "IstreamGenerator.h"
using namespace std;
miit::algebra::IstreamGenerator::IstreamGenerator(istream& in) : in(in) {};
int miit::algebra::IstreamGenerator::generate() {
	int value = 0;
	this->in >> value;
	return value;
}