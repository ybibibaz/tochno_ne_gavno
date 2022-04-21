#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Matrix.hpp"


using namespace std;


void construct_test() {
	int* test = new int[5];
	for (int i = 0; i < 5; i++) {
		test[i] = i;
	}
	float* test1 = new float[5];
	for (int i = 0; i < 5; i++) {
		test1[i] = float(i);
	}
	Matrix<int>* a = new Matrix<int>();
	Matrix<int>* b = new Matrix<int>(test, 5);
	Matrix<float>* c = new Matrix<float>();
	Matrix<float>* d = new Matrix<float>(test1, 5);
	cout << "construct test passed" << endl;
	delete[] test;
	delete[] test1;
	delete a;
	delete b;
	delete c;
	delete d;
}
void int_mult_test() {
	Matrix<int>* a = new Matrix<int>();
	a->Append(0);
	a->Append(1);
	a->Append(2);
	int b = 5;
	a = a->mult(b);
	if (a->Get(0) == 0 && a->Get(1) == 5 && a->Get(2) == 10) {
		cout << "int mult test passed" << endl;
	}
	else {
		cout << "int mult test not passed" << endl;
	}
	delete a;
}
void float_mult_test() {
	Matrix<float>* a = new Matrix<float>();
	a->Append(0);
	a->Append(1.2);
	a->Append(2.4);
	float b = 0.5;
	a = a->mult(b);
	if (a->Get(0) == float(0) && a->Get(1) == float(0.6) && a->Get(2) == float(1.2)) {
		cout << "float mult test passed" << endl;
	}
	else {
		cout << "float mult test not passed" << endl;
	}
	delete a;
}
void int_plus_test() {
	Matrix<int>* a = new Matrix<int>();
	Matrix<int>* b = new Matrix<int>();
	a->Append(0);
	a->Append(1);
	a->Append(2);
	b->Append(1);
	b->Append(2);
	b->Append(3);
	a = a->plus(b);
	if (a->Get(0) == 1 && a->Get(1) == 3 && a->Get(2) == 5) {
		cout << "int plus test passed" << endl;
	}
	else {
		cout << "int plus test not passed" << endl;
	}
	delete a;
	delete b;
}
void float_plus_test() {
	Matrix<float>* a = new Matrix<float>();
	Matrix<float>* b = new Matrix<float>();
	a->Append(0.1);
	a->Append(1.2);
	a->Append(2.3);
	b->Append(1.1);
	b->Append(2.2);
	b->Append(3.3);
	a = a->plus(b);
	if (a->Get(0) == float(1.2) && a->Get(1) == float(3.4) && a->Get(2) == float(5.6)) {
		cout << "float plus test passed" << endl;
	}
	else {
		cout << "float plus test not passed" << endl;
	}
	delete a;
	delete b;
}
void int_norm_test() {
	Matrix<int>* a = new Matrix<int>();
	a->Append(0);
	if (a->norm() == 0) {
		a->Append(-1);
		if (a->norm() == 1) {
			a->Append(2);
			if (a->norm() == 2) {
				cout << "int norm test passed" << endl;
			}
			else {
				cout << "int norm test not passed" << endl;
			}
		}
		else {
			cout << "int norm test not passed" << endl;
		}
	}
	else {
		cout << "int norm test not passed" << endl;
	}
	delete a;
}
void float_norm_test() {
	Matrix<float>* a = new Matrix<float>();
	a->Append(0.4);
	if (a->norm() == float(0.4)) {
		a->Append(-1.3);
		if (a->norm() == float(1.3)) {
			a->Append(2.8);
			if (a->norm() == float(2.8)) {
				cout << "float norm test passed" << endl;
			}
			else {
				cout << "float norm test not passed" << endl;
			}
		}
		else {
			cout << "float norm test not passed" << endl;
		}
	}
	else {
		cout << "float norm test not passed" << endl;
	}
}