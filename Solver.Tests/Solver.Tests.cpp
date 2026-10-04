#include "CppUnitTest.h"
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/ConstantGenerator.h"
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
			size_t n = 2;
			size_t m = 2;
			//Act
			Matrix test_matrix(n, m);
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), n);
			Assert::AreEqual(test_matrix.get_columns(), m);
		}
		TEST_METHOD(Creat_matrix_using_other_matrix) {
			//Arage
			Matrix other(2, 2);
			other[0][0] = 1; other[0][1] = 2;
			other[1][0] = 3; other[1][1] = 4;
			//Act
			Matrix test_matrix(other);
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), other.get_rows());
			Assert::AreEqual(test_matrix.get_columns(), other.get_columns());
			for (size_t i(0); i < test_matrix.get_rows(); i++) {
				for (size_t j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix[i][j], other[i][j]);
				}
			}
		}
		TEST_METHOD(Creating_using_assigment_operator) {
			//Arage
			Matrix other(2, 2);
			other[0][0] = 1; other[0][1] = 2;
			other[1][0] = 3; other[1][1] = 4;
			//Act
			Matrix test_matrix = other;
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), other.get_rows());
			Assert::AreEqual(test_matrix.get_columns(), other.get_columns());
			for (size_t i(0); i < test_matrix.get_rows(); i++) {
				for (size_t j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix[i][j], other[i][j]);
				}
			}
		}
		TEST_METHOD(Delete_column) {
			//Arage
			Matrix test_matrix(2, 2);
			test_matrix[0][0] = 1; test_matrix[0][1] = 2;
			test_matrix[1][0] = 3; test_matrix[1][1] = 4;
			//Act
			test_matrix.delete_comlun(0);
			//Assert
			Assert::AreEqual(test_matrix.get_columns(), 1ULL);
		}
		TEST_METHOD(Matrix_are_equal) {
			//Arage
			Matrix test_matrix(2, 2);
			test_matrix[0][0] = 1; test_matrix[0][1] = 2;
			test_matrix[1][0] = 3; test_matrix[1][1] = 4;
			Matrix other(2, 2);
			other[0][0] = 1; other[0][1] = 2;
			other[1][0] = 3; other[1][1] = 4;
			//Act
			//Assert
			Assert::IsTrue(test_matrix == other);
		}
		TEST_METHOD(Move_Constructor) {
			//Arage
			Matrix other(2, 2);
			other[0][0] = 1; other[0][1] = 2;
			other[1][0] = 3; other[1][1] = 4;
			//Act
			Matrix test_matrix(std::move(other));
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), 2ULL);
			Assert::AreEqual(test_matrix.get_columns(), 2ULL);
			Assert::AreEqual(test_matrix[0][0], 1);
			Assert::AreEqual(test_matrix[0][1], 2);
			Assert::AreEqual(test_matrix[1][0], 3);
			Assert::AreEqual(test_matrix[1][1], 4);
			Assert::AreEqual(other.get_rows(), 0ULL);
			Assert::AreEqual(other.get_columns(), 0ULL);
		}
		TEST_METHOD(Move_Assignment_Operator) {
			//Arage
			Matrix test_matrix(2, 2);
			Matrix other(2, 2);
			other[0][0] = 1; other[0][1] = 2;
			other[1][0] = 3; other[1][1] = 4;
			//Act
			test_matrix = std::move(other);
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), 2ULL);
			Assert::AreEqual(test_matrix.get_columns(), 2ULL);
			Assert::AreEqual(test_matrix[0][0], 1);
			Assert::AreEqual(test_matrix[0][1], 2);
			Assert::AreEqual(test_matrix[1][0], 3);
			Assert::AreEqual(test_matrix[1][1], 4);
			Assert::AreEqual(other.get_rows(), 0ULL);
			Assert::AreEqual(other.get_columns(), 0ULL);
		}
		TEST_METHOD(Random_Generator_Range) {
			//Arage
			const int min = 10;
			const int max = 20;
			RandomGenerator randGen(min, max);
			//Act/Assert
			for (size_t i(0); i < 100; i++) {
				int generated_value = randGen.generate();
				Assert::IsTrue(generated_value >= min);
				Assert::IsTrue(generated_value <= max);
			}
		}
		TEST_METHOD(Random_Generator_Unique) {
			//Arage
			RandomGenerator randGen(1, 1000);
			//Act
			int first_value = randGen.generate();
			int second_value = randGen.generate();
			size_t attempts(0);
			while (first_value == second_value && attempts < 5) {
				second_value = randGen.generate();
				attempts++;
			}
			// Assert
			Assert::IsFalse(first_value == second_value);
		}
		TEST_METHOD(Constant_Generator)
		{
			// Arrange
			const int expected_constant = 42;
			ConstantGenerator constGen(expected_constant);

			// Act & Assert
			Assert::AreEqual(expected_constant, constGen.generate());
			Assert::AreEqual(expected_constant, constGen.generate());
			Assert::AreEqual(expected_constant, constGen.generate());
		}
		TEST_METHOD(Matrix_fill) {
			//Arrange
			Matrix test_matrix(2, 2);
			ConstantGenerator gen(42);
			//Act
			test_matrix.fill_random(&gen);
			//Assert
			for (size_t i(0); i < test_matrix.get_rows(); i++) {
				for (size_t j(0); j < test_matrix.get_columns(); j++) {
					Assert::AreEqual(test_matrix[i][j], 42);
				}
			}
		}
		TEST_METHOD(Task_1) {
			Matrix test_matrix(2, 2);
			test_matrix[0][0] = 1; test_matrix[0][1] = 2;
			test_matrix[1][0] = 3; test_matrix[1][1] = 4;
			RandomGenerator MyGenerator(-10, 10);
			//Act
			Task1 task1(&test_matrix, &MyGenerator);
			task1.solve();
			//Assert
			Assert::AreEqual(test_matrix[0][0], 0);
			Assert::AreEqual(test_matrix[1][0], 0);
			Assert::AreEqual(test_matrix[0][1], 2);
			Assert::AreEqual(test_matrix[1][1], 4);
		}
		TEST_METHOD(Task_2) {
			Matrix test_matrix(2, 2);
			test_matrix[0][0] = 1; test_matrix[0][1] = 2;
			test_matrix[1][0] = 3; test_matrix[1][1] = 4;
			RandomGenerator MyGenerator(-10, 10);
			//Act
			Task2 task2(&test_matrix, &MyGenerator);
			task2.solve();
			//Assert
			Assert::AreEqual(test_matrix.get_rows(), 2ULL);
			Assert::AreEqual(test_matrix.get_columns(), 1ULL);
			Assert::AreEqual(test_matrix[0][0], 2);
			Assert::AreEqual(test_matrix[1][0], 4);
		}
	};
}