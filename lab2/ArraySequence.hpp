#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"
#include "Exception.hpp"
#include <string>
#include <iostream>


template <class T>
class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T>* items;
public:
	ArraySequence(T* items, int count) {
		try {
			this->items = new DynamicArray<T>(items, count);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	};
	ArraySequence() {
		try {
			this->items = new DynamicArray<T>();
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	ArraySequence(const ArraySequence<T>& items) {
		try {
			this->items = new DynamicArray<T>();
			for (int i = 0; i < items.GetLength(); i++) {
				this->Append(items.Get(i));
			}
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
public:
	virtual int GetLength() const override {
		return this->items->GetSize();
	}
	virtual T GetFirst() const override {
		try {
			return this->items->Get(0);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	virtual T GetLast() const override {
		try {
			return this->items->Get(this->items->GetSize() - 1);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	};
	virtual T Get(const int index) const override {
		try {
			return this->items->Get(index);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	};
	virtual Sequence<T>* GetSubsequence(const int start, const int end) const override {
		ArraySequence<T>* temp = new ArraySequence<T>();
		for (int i = 0; i < end - start + 1; i++) {
			temp->Append(this->Get(start + i));
		}
		return temp;
	};
public:
	virtual void Append(T value) override {
		this->items->Resize(this->GetLength() + 1);
		this->items->Set(this->GetLength() - 1, value);
	}
	virtual void Prepend(T value) override {
		this->items->Resize(this->GetLength() + 1);
		for (int i = this->GetLength() - 1; i > 0; i--) {
			this->items->Set(i, this->items->Get(i - 1));
		}
		this->items->Set(0, value);
	}
	virtual void InsertAt(const int index, T value) override {
		try {
			this->items->InsertAt(value, index);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	virtual void RemoveAt(const int index) override {
		try {
			this->items->RemoveAt(index);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	virtual void Remove(T value) override {
		this->items->Remove(value);
	}
	virtual void RemoveAll(T value) override {
		this->items->RemoveAll(value);
	}
	virtual void Swap(int index1, int index2) override {
		try {
			this->items->Swap(index1, index2);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	virtual Sequence<T>* Concat(Sequence<T>* other) override {
		ArraySequence<T>* temp = new ArraySequence<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			temp->Append(temp->Get(i));
		}
		for (int i = 0; i < other->GetLength(); i++) {
			temp->Append(other->Get(i));
		}
		return temp;
	}

public:
	virtual ~ArraySequence() {
		delete this->items;
	}
};
