#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"
#include "Exception.hpp"
#include <string>
#include <iostream>


template <class T>
class ListSequence : public Sequence<T>
{
private:
	LinkedList<T>* items;
public:
	ListSequence(T* items, int count) {
		try {
			this->items = new LinkedList<T>(items, count);
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	};
	ListSequence() {
		try {
			this->items = new LinkedList<T>();
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	ListSequence(const ListSequence<T>& items) {
		try {
			this->items = new LinkedList<T>();
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
		return this->items->GetLength();
	}
	virtual T GetFirst() const override {
		try {
			return this->items->GetFirst();
		}
		catch (Exception & exception) {
			std::cout << exception.getError();
		}
	}
	virtual T GetLast() const override {
		try {
			return this->items->GetLast();
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
		ListSequence<T>* temp = new ListSequence<T>();
		temp->items = this->items->GetSubList(start, end);
		return temp;
	};
public:
	virtual void Append(T value) override {
		this->items->Append(value);
	}
	virtual void Prepend(T value) override {
		this->items->Prepend(value);
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
		ListSequence<T>* temp = new ListSequence<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			temp->Append(temp->Get(i));
		}
		for (int i = 0; i < other->GetLength(); i++) {
			temp->Append(other->Get(i));
		}
		return temp;
	}

public:
	virtual ~ListSequence() {
		delete this->items;
	}
};
