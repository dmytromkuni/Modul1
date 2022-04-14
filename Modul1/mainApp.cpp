#include "header1.h"
#include "header2.h"
#include "header3.h"

#include <iostream>

void main()
{
	//MODUL 1 - TASK 1
	char NAME1[] = "task1.txt";

	modul_task1::Task1(NAME1);


	//MODUL 1 - TASK 2
	char to_dup[] = "1222344511";
	modul_task2::ListDup list2;

	list2.addArr(to_dup);
	list2.printList();
	list2.Task2();
	list2.printList();


	//MODUL 1 - TASK 3
	modul_task3::ListRand list3;

	list3.random(100, 1000);
	list3.printList();

	int N = 10;
	modul_task3::ListRand* arr_list = list3.Task3(N);
	/* 
	for (int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		arr_list[i].printList();
	}
	*/
	bool search = modul_task3::search(arr_list, 543, N);
}