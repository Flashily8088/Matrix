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
			Assert::AreEqual(test_matrix.get_rows(), other.get_rows());
			Assert::AreEqual(test_matrix.get_columns(), other.get_rows());
			for (int i(0); i < test_matrix.get_rows(); i++) {
				for (int j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix.get_element(i, j), other.get_element(i, j));
				}
			}
		}
		TEST_METHOD(Creating_using_assigment_operator) {
			Matrix other(2, 2);
			other.at(0, 0) = 1; other.at(0, 1) = 2;
			other.at(1, 0) = 3; other.at(1, 1) = 4;
			//Act
			Matrix test_matrix = other;
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), other.get_rows());
			Assert::AreEqual(test_matrix.get_columns(), other.get_columns());
			for (int i(0); i < test_matrix.get_rows(); i++) {
				for (int j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix.get_element(i, j), other.get_element(i, j));
				}
			}
		}
		TEST_METHOD(Delete_column) {
			Matrix test_matrix(2, 2);
			test_matrix.at(0, 0) = 1; test_matrix.at(0, 1) = 2;
			test_matrix.at(1, 0) = 2; test_matrix.at(1, 1) = 4;
			//Act
			test_matrix.delete_comlun(0);
			//Assert
			Assert::AreEqual(test_matrix.get_columns(), 1);
		}
		TEST_METHOD(Matrix_are_equal) {
			Matrix test_matrix(2, 2);
			test_matrix.at(0, 0) = 1; test_matrix.at(0, 1) = 2;
			test_matrix.at(1, 0) = 3; test_matrix.at(1, 1) = 4;
			Matrix other(2, 2);
			other.at(0, 0) = 1; other.at(0, 1) = 2;
			other.at(1, 0) = 3; other.at(1, 1) = 4;
			//Act
			//Assert
			Assert::IsTrue(test_matrix == other);
		}
		TEST_METHOD(Task_1) {
			Matrix test_matrix(2, 2);
			test_matrix.at(0, 0) = 1; test_matrix.at(0, 1) = 2;
			test_matrix.at(1, 0) = 3; test_matrix.at(1, 1) = 4;
			RandomGenerator MyGenerator(-10, 10);
			//Act
			Task1 task1(&test_matrix, &MyGenerator);
			task1.solve();
			//Assert
			Assert::AreEqual(test_matrix.get_element(0, 0), 0);
			Assert::AreEqual(test_matrix.get_element(1, 0), 0);
			Assert::AreEqual(test_matrix.get_element(0, 1), 2);
			Assert::AreEqual(test_matrix.get_element(1, 1), 4);
		}
		TEST_METHOD(Task_2) {
			Matrix test_matrix(2, 2);
			test_matrix.at(0, 0) = -1; test_matrix.at(0, 1) = 2;
			test_matrix.at(1, 0) = 3; test_matrix.at(1, 1) = 4;
			RandomGenerator MyGenerator(-10, 10);
			//Act
			Task2 task2(&test_matrix, &MyGenerator);
			task2.solve();
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), 2);
			Assert::AreEqual(test_matrix.get_columns(), 1);
			Assert::AreEqual(test_matrix.get_element(0, 0), -1);
			Assert::AreEqual(test_matrix.get_element(1, 0), 3);
		}
	};
}