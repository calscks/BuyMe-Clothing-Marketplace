#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList
{
	Node<T> *head, *tail, *temp, *cur;
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	~LinkedList();
	void appendFront(T data);
	void append(T data);
	void appendPosition(T data, int& position);
	void traversePrint() const;
	void traverseRevPrint() const;
	void singlePrint() const;
	int getSize();
	T getData(int& position);
	void destroy(T data);
};

#endif
