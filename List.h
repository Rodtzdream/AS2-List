#pragma once
#include <iostream>

struct Node
{
	Node(int data)
	{
		this->data = data;
		Next = nullptr;
		Last = nullptr;
	}
	int data;
	Node* Next;
	Node* Last;
};

class List
{
public:
	List();
	List(const List& other);
	~List();

	void makenull();
	Node* first();
	Node* end();
	void insert(int data, int index);
	void push_back(int data);
	void pop_back();
	void push_front(int data);
	void pop_front();
	void Delete(int index);
	Node* locate(int data);
	int retrieve(int index);
	Node* previous(int index);
	Node* next(int index);

	void printlist();

private:
	void remove(Node* temp);
	Node* head;
	Node* tail;
	int SIZE;
};

#include "List.h"

List::List(const List& other)
{
	head = nullptr;
	tail = nullptr;
	SIZE = 0;
	Node* temp = other.head;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->Next;
	}
}

List::List()
{
	head = nullptr;
	tail = nullptr;
	SIZE = 0;
}

List::~List()
{
	makenull();
}

void List::makenull()
{
	int temp = SIZE;
	for (int i = 0; i < temp; i++)
	{
		pop_front();
	}
}

Node* List::first()
{
	return head;
}

Node* List::end()
{
	return tail;
}

void List::insert(int data, int index)
{
	if (index == 0)
		push_front(data);
	else if (index == SIZE)
		push_back(data);
	else
	{
		Node* temp;
		if (index <= SIZE / 2)
		{
			temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->Next;
			}
		}
		else
		{
			temp = tail;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->Last;
			}
		}
		Node* temp2 = new Node(data);
		temp2->Last = temp;
		temp2->Next = temp->Next;
		temp->Next = temp2;
		SIZE++;
	}
}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else if (tail == nullptr)
	{
		tail = new Node(data);
		head->Next = tail;
		tail->Last = head;
	}
	else
	{
		Node* temp = tail;
		tail = new Node(data);
		temp->Next = tail;
		tail->Last = temp;
	}
	SIZE++;
}

void List::pop_back()
{
	if (tail->Last)
	{
		Node* temp = tail->Last;
		temp->Next = nullptr;
		delete tail;
		tail = temp;
	}
	else
	{
		delete tail;
		tail = nullptr;
	}
	SIZE--;
}

void List::push_front(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else if (tail == nullptr)
	{
		tail = head;
		head = new Node(data);
		head->Next = tail;
		tail->Last = head;
	}
	else
	{
		Node* temp = head;
		head = new Node(data);
		head->Next = temp;
		temp->Last = head;
	}
	SIZE++;
}

void List::pop_front()
{
	if (head->Next)
	{
		Node* temp = head->Next;
		temp->Last = nullptr;
		delete head;
		head = temp;
		if (head->Next == tail)
			tail = nullptr;
	}
	else
	{
		delete head;
		head = nullptr;
	}
	SIZE--;
}

void List::Delete(int index)
{
	remove(locate(index));
}

Node* List::locate(int index)
{
	Node* temp;
	if (index <= SIZE / 2)
	{
		temp = head;
		int currentindex = 0;
		while (temp != nullptr)
		{
			if (currentindex == index)
				return temp;
			temp = temp->Next;
			currentindex++;
		}
	}
	else
	{
		temp = tail;
		int currentindex = SIZE - 1;
		while (temp != nullptr)
		{
			if (currentindex == index)
				return temp;
			temp = temp->Last;
			currentindex--;
		}
	}
	return 0;
}

int List::retrieve(int index)
{
	Node* temp;
	if (index <= SIZE / 2)
	{
		temp = head;
		int currentindex = 0;
		while (temp != nullptr)
		{
			if (currentindex == index)
				return temp->data;
			temp = temp->Next;
			currentindex++;
		}
	}
	else
	{
		temp = tail;
		int currentindex = SIZE - 1;
		while (temp != nullptr)
		{
			if (currentindex == index)
				return temp->data;
			temp = temp->Last;
			currentindex--;
		}
	}
	return 0;
}

Node* List::previous(int index)
{
	Node* temp = head;
	int currentindex = 0;
	while (temp != nullptr)
	{
		if (currentindex == index)
			return temp->Last;
		temp = temp->Next;
		currentindex++;
	}
	return nullptr;
}

Node* List::next(int index)
{
	Node* temp = head;
	int currentindex = 0;
	while (temp != nullptr)
	{
		if (currentindex == index)
			return temp->Next;
		temp = temp->Next;
		currentindex++;
	}
	return nullptr;
}

void List::printlist()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->Next;
	}
}

void List::remove(Node* temp)
{
	if (head == temp)
		pop_front();
	else if (tail == temp)
		pop_back();
	else
	{
		Node* temp2 = temp->Last;
		Node* temp3 = temp->Next;
		temp2->Next = temp3;
		temp3->Last = temp2;
		delete temp;
	}
	SIZE--;
}