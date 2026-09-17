#include "Matrix.h"
#include "Task2.h"
namespace miit::algebra {
	miit::algebra::Task2::Task2(Matrix* m, Generator* g) : Exercise(m, g) {}
	void Task2::solve()
	{
		for (int j = matrix->get_columns(); j >= 0; j--) {
			bool flag(false);
			for (int i(0); i < matrix->get_rows(); i++) {
				int element = matrix->get_element(i, j);
				if (element % 2 != 0 && element > 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				matrix->delete_comlun(j);
			}
		}
	}
}
