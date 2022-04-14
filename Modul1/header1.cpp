#include "header1.h"

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

modul_task1::Stack::Node::Node(int value)
{
	this->value = value;
}

void modul_task1::Stack::printStack()
{
	Node* iter1 = head;
	while (iter1 != nullptr)
	{
		std::cout << iter1->value << " ";
		iter1 = iter1->next;
	}
	std::cout << "\n\n";
}

int modul_task1::Stack::pop()
{
	Node* iter1 = tail;

	int result;

	if (iter1 != nullptr)
	{
		result = iter1->value;

		if (iter1->prev != nullptr)
		{
			tail->prev->next = nullptr;
			Node* temp = tail;
			tail = tail->prev;
			delete(temp);
			temp = NULL;
		}

		else 
		{
			Node* temp = tail;
			tail = nullptr;
			head = nullptr;
			delete(temp);
			temp = NULL;
		}

		return result;
	}


	else
	{
		std::cout << "NO MORE ELEMENTS IN THE STACK";
		return 0;
	}
}

void modul_task1::Stack::add(int num)
{
	Node* node = new Node(num);
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void modul_task1::Task1(char* const NAME)
{
	std::ifstream out(NAME, std::ifstream::in);
	modul_task1::Stack stack;

	const int SIZE = 8;
	char buffer[SIZE];

	while (!out.eof())
	{
		memset(buffer, 'A', sizeof(buffer));
		out.read((char*)&buffer, sizeof(buffer));
		for (int i = 0; i < SIZE; i++)
		{
			if (buffer[i] == '-' || buffer[i] == '+' || buffer[i] == '*')
			{
				int temp1 = stack.pop();
				int temp2 = stack.pop();
				if (buffer[i] == '-') stack.add(temp1 - temp2);
				else if (buffer[i] == '+') stack.add(temp1 + temp2);
				else if (buffer[i] == '*') stack.add(temp1 * temp2);
			}
			else if (buffer[i] == ' ') continue;
			else if (isdigit(buffer[i]))
			{
				int to_add = buffer[i] - '0';
				stack.add(to_add);
			}
			else
			{
				stack.printStack();
				return;
			}
		}
	}
}
