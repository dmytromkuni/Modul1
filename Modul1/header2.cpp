#include "header2.h"

#include <iostream>

modul_task2::ListDup::Node::Node(char value)
{
	this->value = value;
}


void modul_task2::ListDup::printList()
{
	Node* iter1 = head;
	while (iter1 != nullptr)
	{
		std::cout << iter1->value;
		iter1 = iter1->next;
	}
	std::cout << "\n\n";
}

void modul_task2::ListDup::addChar(char val)
{
	Node* node = new Node(val);
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}

void modul_task2::ListDup::addArr(char* arr)
{
	for (int i = 0; i < strlen(arr); i++)
		this->addChar(arr[i]);
}

void modul_task2::ListDup::Task2()
{
	Node* iter1 = head;

	while (iter1->next != nullptr)
	{
		if (iter1->next->value == iter1->value)
		{
			if (iter1->next == tail) tail = iter1;
			Node* temp = iter1->next;
			iter1->next = iter1->next->next;
			delete(temp);
			temp = NULL;
			continue;
		}
		
		else iter1 = iter1->next;
	}
}
