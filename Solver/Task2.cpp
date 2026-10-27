#include "Matrix.h"
#include "Task2.h"
namespace miit::algebra {
	miit::algebra::Task2::Task2(Matrix& m, const Generator& g) : Exercise(m, g) {};
	void Task2::solve()
	{
		vector<size_t> indexes;
		for (size_t j(0); j < matrix.get_columns(); j++) {
			bool flag(false);
			for (int i(0); i < matrix.get_rows(); i++) {
				int element = matrix[i][j];
				if (element % 2 != 0 && element > 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				indexes.push_back(j);
			}
		}
		for (size_t i(indexes.size()); i > 0; i--) {
			matrix.delete_comlumn(indexes[i-1]);
		}
	}
}
