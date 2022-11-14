#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void DInicMatrix(int**& a, int& m, int& n) {
	cout << "Type M - number of columns!" << endl;
	cin >> m;
	cout << "Type N - number of rows!" << endl;
	cin >> n;
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
}

void ZerosMatrix(int**& a, int m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
}

void RandomsMatrix(int**& a, int m, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100 - 50;
		}
	}
}

void MassOutputCube(int**& a, int m, int n) {
	cout << "-----------------------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------" << endl;
}

void DelMatrix(int**& a, int n) {
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
}

void IinRow(int**& a, int m, int n) {
	int I;
	cout << "Type I - row which will be filled 10 * I" << endl;
	cin >> I;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == I) {
				a[i][j] = I * 10;
			}
		}
	}
}

int mini(int a, int b) {
	if (a > b) return b;
	return a;
}

void Swapper(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void LowestInARow(int**& a, int m, int n) {
	int lowest;
	for (int i = 0; i < n; i++) {
		lowest = 1000;
		for (int j = 0; j < m; j++) {
			lowest = mini(lowest, a[i][j]);
		}
		cout << lowest << endl;
	}
}

int SearchForColomn(int** a, int m, int n) {
	int Counter;
	int Stol = 0;
	for (int i = 0; i < m; i++) {
		Counter = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] > 0) Counter++;
		}
		if (Counter == n) {
			Stol = i;
		}
	}
	return Stol;
}

void MatrixReplaceCol(int**& a, int m, int n) {
	int Col = SearchForColomn(a, m, n);
	if (Col != 0) {
		for (int i = 0; i < n; i++) {
			Swapper(a[i][0], a[i][Col]);
		}
	}
}

void Matrix1() {
	int** a;
	int n, m;
	DInicMatrix(a, m, n);
	ZerosMatrix(a, m, n);
	IinRow(a, m, n);
	MassOutputCube(a, m, n);
	DelMatrix(a, n);
}

void Matrix23() {
	int** a;
	int n, m;
	DInicMatrix(a, m, n);
	RandomsMatrix(a, m, n);
	MassOutputCube(a, m, n);
	LowestInARow(a, m, n);
	DelMatrix(a, n);
}

void Matrix53() {
	int** a;
	int n, m;
	DInicMatrix(a, m, n);
	RandomsMatrix(a, m, n);
	MassOutputCube(a, m, n);
	MatrixReplaceCol(a, m, n);
	MassOutputCube(a, m, n);
	DelMatrix(a, n);
}