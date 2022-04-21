#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include <cmath>
using namespace std;


template <typename T> T max(T value1, T value2) {
	if (value1 >= value2) {
		return value1;
	}
	else {
		return value2;
	}

}


template <class T>
class Matrix
{
private:
	Sequence<T>* items;
public:
	Matrix() {
		this->items = new ArraySequence<T>();
	}
	Matrix(T* items, int count) {
		this->items = new ArraySequence<T>(items, count);
	}
public:
	int GetLength() const {
		return this->items->GetLength();
	}
	T Get(int index) const {
		return this->items->Get(index);
	}
	void Append(T value) {
		this->items->Append(value);
	}
	void print() {
		for (int i = 0; i < this->GetLength(); i++) {
			for (int j = 0; j < this->GetLength(); j++) {
				if (i == j) {
					cout << this->Get(i) << " ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
	}
	void input(int size) {
		T n;
		for (int i = 0; i < size; i++) {
			cout << "Введите элемент с номером " << i << endl;
			cin >> n;
			this->Append(n);
		}
	}
	Matrix<T>* mult(T value) {
		Matrix<T>* temp = new Matrix<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			T temp_value = this->Get(i) * value;
			temp->Append(temp_value);
		}
		return temp;
	}
	Matrix<T>* plus (Matrix<T>* other){
		Matrix<T>* temp = new Matrix<T>();
		for (int i = 0; i < max(this->GetLength(), other->GetLength()); i++) {
			if (i < this->GetLength() && i < other->GetLength()) {
				temp->Append(this->Get(i) + other->Get(i));
			}
			else if (i > this->GetLength()) {
				temp->Append(other->Get(i));
			}
			else if (i > other->GetLength()) {
				temp->Append(this->Get(i));
			}
		}
		return temp;
	}
	T norm() {
		if (this->GetLength() == 0) {
			cout << "empty" << endl;
		}
		else {
			T temp = abs(this->Get(0));
			for (int i = 1; i < this->GetLength(); i++) {
				temp = max(temp, abs(this->Get(i)));
			}
			return temp;
		}
	}
public:
	~Matrix() {
		delete this->items;
	}
	void fake_delete() {
		delete this->items;
		this-> items = new ArraySequence<T>();
	}
};
