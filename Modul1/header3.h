#pragma once

namespace modul_task3
{
	struct ListRand
	{
		struct Node
		{
			int value;
			Node* next = nullptr;
			Node(int value);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		void printList();
		void add(int val);
		void random(int AMOUNT, int MAX);
		ListRand* Task3(int N);
	};
	int sumDigits(int x);
	bool search(ListRand* arr, int number, int N);
}
