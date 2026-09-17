#include "Matrix.h"
#include "Task1.h"

namespace miit::algebra {
	Task1::Task1(Matrix* m, Generator* g) : Exercise(m, g) {};

	void Task1::solve()
	{
		for (int i(0); i < matrix->get_rows(); i++) {
			int min = matrix->get_element(i, 0);
			int min_j = 0;
			for (int j(1); j < matrix->get_columns(); j++) {
				if (matrix->get_element(i, j) < min) {
					min = matrix->get_element(i, j);
					min_j = j;
				}
			}
			matrix->at(i, min_j) = 0;
		}
	}
}