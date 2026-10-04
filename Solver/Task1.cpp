#include "Matrix.h"
#include "Task1.h"

namespace miit::algebra {
	Task1::Task1(Matrix* m, const Generator* g) : Exercise(m, g) {};

	void Task1::solve()
	{
		for (int i(0); i < matrix->get_rows(); i++) {
			int min = (*matrix)[i][0];
			int min_j = 0;
			for (int j(1); j < matrix->get_columns(); j++) {
				if ((*matrix)[i][j] < min) {
					min = (*matrix)[i][j];
					min_j = j;
				}
			}
			(*matrix)[i][min_j] = 0;
		}
	}
}