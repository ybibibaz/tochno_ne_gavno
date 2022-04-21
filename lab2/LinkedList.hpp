#pragma once
#include <string>
#include "Exception.hpp"


template <class T> class Node
{
public:
    T value;
    Node<T>* next;
};


template <class T> class LinkedList
{
private:
    Node<T>* head;
    int size;
public:
    LinkedList() {
        this->size = 0;
    };
    LinkedList(T* items, int count) {
        this->size = count;
        this->head = new Node<T>;
        this->head->value = items[0];
        Node<T>* temp = this->head;
        for (int i = 1; i < count; i++) {
            temp->next = new Node<T>;
            temp = temp->next;
            temp->value = items[i];
        }
    };
    LinkedList(const LinkedList<T>& list) {
        this->size = list.GetLength();
        if (size != 0) {
            this->head = new Node<T>;
            this->head->value = list.Get(0);
            Node<T>* temp = this->head;
            for (int i = 1; i < list.GetLength(); i++) {
                temp->next = new Node<T>;
                temp = temp->next;
                temp->value = list.Get(i);
            }
        }
    };
public:
    T GetFirst() const {
        if (!this->head) 
            throw Exception("EmptyList");
        return this->head->value;
    };
    T GetLast() const {
        if (!this->head) 
            throw Exception("EmptyList");
        Node<T>* temp = this->head;
        for (int i = 0; i < this->size - 1; i++) {
                temp = temp->next;
        }
        return temp->value;
    };
    T Get(int index) const {
        if (index < 0 || index > this->size - 1)
            throw Exception("IndexOutOfRange");
        if (!this->head)
            throw Exception("EmptyList");
        Node<T>* temp = this->head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
    int GetLength() const {
        return this->size;
    }
public:
    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex > this->size - 1 || startIndex > endIndex)
            throw Exception("IndexOutOfRange");
        LinkedList<T>* res = new LinkedList<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            res->Append(this->Get(i));
        }
        return res;
    };
    void Append(T item) {
        if (size == 0) {
            this->head = new Node<T>;
            this->head->value = item;
            this->size++;
        }
        else {
            Node<T>* temp = this->head;
            for (int i = 0; i < size - 1; i++) {
                temp = temp->next;
            }
            temp->next = new Node<T>;
            temp = temp->next;
            temp->value = item;
            this->size++;
        }
    };
    void Prepend(T item) {
        if (size == 0) {
            this->head = new Node<T>;
            this->head->value = item;
            this->size++;
        }
        else {
            Node<T>* temp = new Node<T>;
            temp->value = item;
            temp->next = this->head;
            this->head = temp;
        }
    };
    void InsertAt(T item, int index) {
        if (index < 0 || index > this->size - 1) 
            throw Exception("IndexOutOfRange");
        Node<T>* temp = this->head;
        if (index == 0)
            this->Prepend(item);
        else if (index == this->size - 1)
            this->Append(item);
        else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node<T>* ins = new Node<T>;
            ins->value = item;
            ins->next = temp->next;
            temp->next = ins;
            this->size++;
        }
    };
    LinkedList<T>* Concat(LinkedList<T>* list) {
        LinkedList<T>* res = new LinkedList<T>();
        for (int i = 0; i < this->size; i++) {
            res->Append(this->Get(i));
        }
        for (int i = 0; i < list->size; i++) {
            res->Append(list->Get(i));
        }

        return res;
    };
    void RemoveAt(const int index) {
        if (index < 0 || index > this->size - 1)
            throw Exception("IndexOutOfRange");
        Node<T>* temp = this->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        if ((index == 0) && (!this->head->next)) {
            delete head;
        }
        else if (index == 0) {
            temp = temp->next;
            delete head;
            this->head = temp;
        }
        else {
            Node<T>* temp1 = temp->next;
            Node<T>* temp2 = temp1->next;
            delete temp1;
            temp->next = temp2;
        }
        this->size--;
    };
    void Swap(int index1, int index2) {
        T value1 = this->Get(index1);
        T value2 = this->Get(index2);
        this->InsertAt(value1, index2);
        this->InsertAt(value2, index1);
    }
    void Remove(T value) {
        if (this->head) {
            int i = 0;
            Node<T>* temp = this->head;
            while ((i < size - 1) and (temp->value != value)) {
                temp = temp->next;
                i++;
            }
            if (i != size - 1) {
                this->RemoveAt(i);
            }
            else if (temp->value == value) {
                this->RemoveAt(i);
            }
        }
    }
    void RemoveAll(T value) {
        if (this->head) {
            int i = 0;
            int n = 0;
            Node<T>* temp = this->head;
            for (i; i < this->size - 1; i++) {
                if (temp->value == value) {
                    n++;
                }
                temp = temp->next;
            }
            if (temp->value == value) {
                n++;
            }
            for (i = 0; i < n; i++) {
                this->Remove(value);
            }
        }
    }
    ~LinkedList() {
        for (int i = 0; i < this->size - 1; i++) {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        delete this->head;
    }
};