#include "header3.h"

#include <iostream>

modul_task3::ListRand::Node::Node(int value)
{
	this->value = value;
}

void modul_task3::ListRand::printList()
{
	Node* iter1 = head;
	while (iter1 != nullptr)
	{
		std::cout << iter1->value << " ";
		iter1 = iter1->next;
	}
	std::cout << "\n\n";
}

void modul_task3::ListRand::add(int val)
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

void modul_task3::ListRand::random(int AMOUNT, int MAX)
{
	for (int i = 0; i < AMOUNT; i++)
		this->add(rand() % MAX + 1);
}

modul_task3::ListRand* modul_task3::ListRand::Task3(int N)
{
	modul_task3::ListRand* result = new modul_task3::ListRand[N];
	Node* iter1 = head;

	for (int i = 0; i < N; i++)
	{
		modul_task3::ListRand to_add;
		result[i] = to_add;
	}

	while (iter1 != nullptr)
	{
		int sum = modul_task3::sumDigits(iter1->value);
		result[sum % N].add(iter1->value);
		iter1 = iter1->next;
	}
	return result;
}

int modul_task3::sumDigits(int x)
{
	x = abs(x);
	int result = 0;
	while (x > 0)
	{
		int reminder = x % 10;
		result += reminder;
		x = (x - reminder) / 10;
	}
	return result;
}

bool modul_task3::search(modul_task3::ListRand* arr, int number, int N)
{
	int idx = modul_task3::sumDigits(number) % N;
	modul_task3::ListRand::Node* iter1 = arr[idx].head;
	while (iter1 != nullptr)
	{
		if (iter1->value == number)
		{
			std::cout << "Succes! Such number exists!\n\n";
			return true;
		}
		else iter1 = iter1->next;
	}
	std::cout << "Unfortunately, such number doesn't exist.\n\n";
	return false;
}
