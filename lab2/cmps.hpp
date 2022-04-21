#pragma once
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include <iostream>
#include <string>

using namespace std;

int cmp(int a, int b) {
	if (a > b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int cmp(float a, float b) {
	if (a > b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int cmp(char a, char b) {
	if ((int)a > (int)b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
