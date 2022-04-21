#pragma once
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "cmps.hpp"
#include "Sorts.hpp"
#include <iostream>
#include <string>

using namespace std;

void Shaker_test() {
	int* test = new int[5];
	for (int i = 0; i < 5; i++) {
		test[i] = rand() % 10;
	}
	float* test1 = new float[5];
	for (int i = 0; i < 5; i++) {
		test1[i] = float(rand() % 10) / float(rand() % 10);
	}
	char* test2 = new char[5];
	for (int i = 0; i < 5; i++) {
		test1[i] = char(32 + rand() % 224);
	}
	ArraySequence<int>* a = new ArraySequence<int>(test, 5);
	ArraySequence<float>* b = new ArraySequence<float>(test1, 5);
	ArraySequence<char>* c = new ArraySequence<char>(test2, 5);
	ListSequence<int>* d = new ListSequence<int>(test, 5);
	ListSequence<float>* e = new ListSequence<float>(test1, 5);
	ListSequence<char>* f = new ListSequence<char>(test2, 5);
	Sequence<int>* g = ShakerSort(a, cmp);
	Sequence<float>* h = ShakerSort(b, cmp);
	Sequence<char>* i = ShakerSort(c, cmp);
	Sequence<int>* j = ShakerSort(d, cmp);
	Sequence<float>* k = ShakerSort(e, cmp);
	Sequence<char>* l = ShakerSort(f, cmp);
	delete[] test;
	delete[] test1;
	delete[] test2;
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete h;
	delete i;
	delete j;
	delete k;
	delete l;
}