#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/IstreamGenerator.h"
#include "../Solver/ConstantGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"

using namespace std;
using namespace miit::algebra;

enum class InputMod {
	Manual = 1,
	Random = 2,
	Const = 3
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
* @brief меню выбора выполнения задания
*/
void task_mod_menu();
/**
* @brief заполнение матрицы
* @param mod - выбор пользователя
* @param MyMatrix - матрица, которую нужно заполн¤ть
* @param gen - генератор
*/
void do_task(const TaskMod mod, Matrix& MyMatrix, const Generator& gen);
/**
* @brief функция проверки корректного ввода
* return false если условие не выполнено
*/
bool check(int param);
/**
* @brief выполнение "Задания 1" и "Задания 2"
* @param rows - количество строк матрицы
* @param columns - количество столбцов матрицы
* @param user_input_mod - выбор пользователя способа заполнения матрицы
* @param user_test_mod - выбор пользователя задания 
* @param MyMatrix - матрица, которую нужно заполнить
* @param gen - генератор
* return 0 если прграмма выполнена успешно
*/
int main() {
	int user_task_mod;
	TaskMod task_mod;
	task_mod_menu();
	cout << "Enter task mod: ";
	cin >> user_task_mod;
	task_mod = static_cast<TaskMod>(user_task_mod);
	if (task_mod != TaskMod::T1 && task_mod != TaskMod::T2) {
		cout << "Not available mod" << endl << endl;
		return 0;
	}
	int rows(0), columns(0);
	cout << endl << "Enter rows: ";
	cin >> rows;
	if(!(check(rows))) return 0;
	cout << "Enter columns: ";
	cin >> columns;
	if (!(check(columns))) return 0;
	Matrix MyMatrix(rows, columns);
	int user_input_mod;
	InputMod input_mod;
	input_mod_menu();
	cout << "Your mod: ";
	cin >> user_input_mod;
	input_mod = static_cast<InputMod>(user_input_mod);
	if (input_mod != InputMod::Random && input_mod != InputMod::Manual && input_mod != InputMod::Const) {
		cout << "Not available mod" << endl << endl;
		return 0;
	}
	switch (input_mod) {
	case InputMod::Manual:
	{
		cin.ignore(10000, '\n');
		cout << "Enter elements using space or Enter" << endl;
		IstreamGenerator local_gen(cin);
		do_task(task_mod, MyMatrix, local_gen);
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
		RandomGenerator local_gen(min, max);
		do_task(task_mod, MyMatrix, local_gen);
		break;
	}
	case InputMod::Const:
	{
		int constant(0);
		cin.ignore(10000, '\n');
		cout << "Enter constant: " << endl;
		cin >> constant;
		ConstantGenerator local_gen(constant);
		do_task(task_mod, MyMatrix, local_gen);
		break;
	}
	default: {
		cout << "Error: Not available mod" << endl;
		return 0;
	}
	}
return 0;
}

void input_mod_menu()
{
	cout << endl << "/// Input menu ///" << endl;
	cout << "1. Fill manually" << endl;
	cout << "2. Fill random" << endl;
	cout << "3. Fill using constant" << endl;
}

void task_mod_menu()
{
	cout << "/// Task menu ///" << endl;
	cout << "1. Do task 1." << endl;
	cout << "2. Do task 2." << endl;
}

void do_task(const TaskMod mod, Matrix& MyMatrix, const Generator& gen)
{
	switch (mod) {
	case (TaskMod::T1): {
		Task1 task1(MyMatrix, gen);
		cout << endl << "Your matrix:" << endl << MyMatrix;
		task1.solve();
		cout << endl << "Task 1" << endl << MyMatrix;
		break;
	}
	case (TaskMod::T2): {
		Task2 task2(MyMatrix, gen);
		cout << endl << "Your matrix:" << endl << MyMatrix;
		task2.solve();
		cout << endl << "Task 2" << endl << MyMatrix;
		break;
	}
	}
}

bool check(int param)
{
	if (param <= 0) {
		cout << "Unavailable index";
		return false;
	}
}
