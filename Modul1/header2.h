#pragma once

namespace modul_task2
{
	struct ListDup
	{
		struct Node
		{
			char value;
			Node* next = nullptr;
			Node(char value);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		void printList();
		void addChar(char val);
		void addArr(char* arr);
		void Task2();
	};
}