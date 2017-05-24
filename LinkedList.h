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
	~LinkedList(); //user-defined destr to free dynamically allocated memories
	typedef std::function<LinkedList<T>()> callback; //should be taking LL as return type, takes no arg (hopefully)
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
		Node() : next(nullptr), prev(nullptr) {};
		Node *next, *prev;
	};
	Node *head, *tail, *temp, *cur;
};

#endif
