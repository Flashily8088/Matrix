#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"

using namespace std;
using namespace miit::algebra;

int main() {
	Matrix MyMatrix(3, 4);
	RandomGenerator MyGenerator(-10, 10);
	MyMatrix.fill_random(&MyGenerator);
	cout << "Before:" << endl << MyMatrix;
	Task1 task1(&MyMatrix, &MyGenerator);
	task1.solve();
	cout << "After:" << endl << MyMatrix;
	Matrix HandMatrix(3, 5);
	cout << "Input:" << endl;
	cin >> HandMatrix;
	Task2 task2(&HandMatrix, &MyGenerator);
	task2.solve();
	cout << "After:" << endl << HandMatrix;
	return 0;
}