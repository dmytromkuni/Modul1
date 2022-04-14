#pragma once

namespace modul_task1
{

	struct Stack
	{
		struct Node
		{
			int value;
			Node* next = nullptr;
			Node* prev = nullptr;
			Node(int value);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		void printStack();
		int pop();
		void add(int num);
	};

	void Task1(char* const NAME);
}