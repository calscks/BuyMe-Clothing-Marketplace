#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <functional>

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>&); //copy constructor
	LinkedList& operator=(LinkedList);
	~LinkedList(); //user-defined destr to free dynamically allocated memories
	typedef std::function<void(LinkedList<T>)> callback; //should be taking void as return type, takes LL as arg (hopefully)
	void appendFront(T data);
	void append(T data);
	void appendPosition(T data, int& position);
	void traversePrint(callback callback) const;
	int getSize();
	void destroy(T data);
private:
	class Node //nested class Node to hide implementation
	{
	public:
		T data;
		Node() : next(nullptr), prev(nullptr) {}
		Node *next, *prev;
	};
	Node *head, *tail, *temp, *cur;
};

#endif
