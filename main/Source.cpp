#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/IstreamGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"

using namespace std;
using namespace miit::algebra;

enum class InputMod {
	Manual = 1,
	Random = 2
};
enum class TaskMod {
	T1 = 1,
	T2 = 2
};
/**
* @brief меню выбора ввода
*/
void input_mod_menu();
/**
* @brief меню выбора выполнени¤ задани¤
*/
void task_mod_menu();
/**
* @brief заполнение матрицы
* @param mod - выбор пользовател¤
* @param MyMatrix - матрица, которую нужно заполн¤ть
* @param gen - генератор
*/
Generator* fill_matrix(InputMod mod, Matrix& MyMatrix);
/**
* @brief выполнение «адани¤ 1 и «адани¤ 2
* @param mod - выбор пользовател¤
* @param MyMatrix - матрица, которую нужно заполн¤ть
* @param gen - генератор
* return 0 если прграмма выполнена успешно
*/
void do_task(TaskMod mod, Matrix& MyMatrix, Generator*& gen);
/**
* @brief выполнение «адани¤ 1 и «адани¤ 2
* @param rows - количество строк матрицы
* @param columns - количество столбцов матрицы
* @param user_input_mod - выбор пользовател¤ способа заполнени¤ матрицы
* @param user_test_mod - выбор пользовател¤ задани¤ 
* @param MyMatrix - матрица, которую нужно заполн¤ть
* @param gen - генератор
* return 0 если прграмма выполнена успешно
*/
int main() {
	size_t rows(0), columns(0);
	cout << "Enter raws: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> columns;
	Matrix MyMatrix(rows, columns);
	int user_input_mod;
	InputMod input_mod;
	do {
		input_mod_menu();
		cout << "Your mod: ";
		cin >> user_input_mod;
		input_mod = static_cast<InputMod>(user_input_mod);
		if (input_mod != InputMod::Random && input_mod != InputMod::Manual) {
			cout << "Not available mod" << endl << endl;
		}
	} while (input_mod != InputMod::Random && input_mod != InputMod::Manual);
	Generator* gen = fill_matrix(input_mod, MyMatrix);
	if (gen == nullptr) {
		gen = new RandomGenerator(1, 10);
	}
	cout << endl << "Your matrix:" << endl << MyMatrix;

	int user_task_mod;
	TaskMod task_mod;
	do {
		task_mod_menu();
		cout << "Yor mod: ";
		cin >> user_task_mod;
		task_mod = static_cast<TaskMod>(user_task_mod);
		if (task_mod != TaskMod::T1 && task_mod != TaskMod::T2) {
			cout << "Not available mod" << endl << endl;
		}
	} while (task_mod != TaskMod::T1 && task_mod != TaskMod::T2);
	do_task(task_mod, MyMatrix, gen);
	return 0;
}

void input_mod_menu()
{
	cout << endl << "/// Input menu ///" << endl;
	cout << "1. Fill manually" << endl;
	cout << "2. Fill random" << endl;
}

void task_mod_menu()
{
	cout << endl << "/// Task menu ///" << endl;
	cout << "1. Do task 1." << endl;
	cout << "2. Do task 2." << endl;
}

Generator* fill_matrix(InputMod mod, Matrix& MyMatrix)
{
	Generator* local_gen = nullptr;
	switch (mod) {
	case InputMod::Manual:
	{
			cout << "Enter elements using space or Enter" << endl;
			local_gen = new IstreamGenerator(cin);
			MyMatrix.fill(local_gen);
			break;
	}
	case InputMod::Random:
	{
			cout << endl << "...Mod of generating..." << endl;
			int max(0), min(0);
			cout << "The minimum: ";
			cin >> min;
			cout << "The maximum: ";
			cin >> max;
			local_gen = new RandomGenerator(min, max);
			MyMatrix.fill(local_gen);
			break;
	}
	return local_gen;
	}
}

void do_task(TaskMod mod, Matrix& MyMatrix, Generator*& gen)
{
	switch (mod) {
	case (TaskMod::T1): {
		Task1 task1(MyMatrix, *gen);
		task1.solve();
		cout << endl << "Task 1" << endl << MyMatrix;
		break;
	}
	case (TaskMod::T2): {
		Task2 task2(MyMatrix, *gen);
		task2.solve();
		cout << endl << "Task 2" << endl << MyMatrix;
		break;
	}
	}
}
