#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"

using namespace std;
using namespace miit::algebra;

/**
* @brief меню выбора
*/
void menu();
/**
* @brief заполнение матрицы
* @param choice - выбор пользовател€
* @param MyMatrix - матрица, которую нужно заполн€ть
* @param gen - генератор
*/
void fill_matrix(int choice, Matrix& MyMatrix, Generator*& gen);
/**
* @brief выполнение «адани€ 1 и «адани€ 2
* @param rows - количество строк матрицы
* @param columns - количество столбцов матрицы
* @param choice - выбор пользовател€
* @param MyMatrix - матрица, которую нужно заполн€ть
* @param gen - генератор
* @param task1 - параметр выполнени€ «адани€ 1
* @param task2 - параметр выполнени€ «адани€ 2
* return 0 если прграмма выполнена успешно
*/
int main() {
	size_t rows(0), columns(0);
	cout << "Enter raws: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> columns;
	Matrix MyMatrix(rows, columns);
	menu();
	int choice;
	cout << "Your choice: ";
	cin >> choice;
	if (choice > 2 || choice < 1) {
		cout << "Not available choice";
		return 1;
	}
	Generator* gen = nullptr;
	fill_matrix(choice, MyMatrix, gen);
	if (gen == nullptr) {
		gen = new RandomGenerator(1, 10);
	}

	cout << "Your matrix:" << endl << MyMatrix;
	Task1 task1(&MyMatrix, gen);
	task1.solve();
	cout << "Task 1" << endl << MyMatrix;
	Task2 task2(&MyMatrix, gen);
	task2.solve();
	cout << "Task 2" << endl << MyMatrix;
	return 0;
}

void menu()
{
	cout << "1. Fill manually" << endl;
	cout << "2. Fill random" << endl;
}

void fill_matrix(int choice, Matrix& MyMatrix, Generator*& gen)
{
	if (choice == 1) {
		cout << "Enter elements using space or Enter" << endl;
		MyMatrix.fill();
	}
	else if (choice == 2) {
		cout <<endl << "...Mod of generating..." << endl;
		int max(0), min(0);
		cout << "The minimum: ";
		cin >> min;
		cout << "The maximum: ";
		cin >> max;
		gen = new RandomGenerator(min, max);
		MyMatrix.fill_random(gen);
	}
}
