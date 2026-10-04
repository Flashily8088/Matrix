#include "Matrix.h"
#include "Task2.h"
namespace miit::algebra {
	miit::algebra::Task2::Task2(Matrix* m, const Generator* g) : Exercise(m, g) {}
	void Task2::solve()
	{
		for (size_t j = matrix->get_columns(); j > 0; j--) {
			size_t actual_j = j - 1;
			bool flag(false);
			for (int i(0); i < matrix->get_rows(); i++) {
				int element = (*matrix)[i][actual_j];
				if (element % 2 != 0 && element > 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				matrix->delete_comlun(actual_j);
			}
		}
	}
}
