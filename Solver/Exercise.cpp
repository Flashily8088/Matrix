#include "Exercise.h"

miit::algebra::Exercise::Exercise(Matrix& m, const Generator& g) : matrix(m), generator(const_cast<Generator&>(g)) {
	matrix.fill(&generator);
}
