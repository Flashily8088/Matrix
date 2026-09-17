#include "CppUnitTest.h"
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace SolverTests
{
	TEST_CLASS(SolverTests)
	{
	public:

		TEST_METHOD(Creat_matrix)
		{
			//Arage
			const int n = 2;
			const int m = 2;
			//Act
			Matrix test_matrix(n, m);
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), n);
			Assert::AreEqual(test_matrix.get_columns(), m);
		}
		TEST_METHOD(Creat_matrix_using_other_matrix) {
			//Arage
			Matrix other(2, 2);
			other.at(0, 0) = 1; other.at(0, 1) = 2;
			other.at(1, 0) = 3; other.at(1, 1) = 4;
			//Act
			Matrix test_matrix(other);
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), 2);
			Assert::AreEqual(test_matrix.get_columns(), 2);
			for (int i(0); i < test_matrix.get_rows(); i++) {
				for (int j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix.get_element(i, j), test_matrix.get_element(i, j));
				}
			}
		}
		TEST_METHOD(Creating_using_move_operator) {
			Matrix other(2, 2);
			other.at(0, 0) = 1; other.at(0, 1) = 2;
			other.at(1, 0) = 3; other.at(1, 1) = 4;
			//Act
			Matrix test_matrix(other);
		}
	};
}