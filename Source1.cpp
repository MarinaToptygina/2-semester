#include "queue.h"
#include <string.h>



void enqueue(queue& q, const char* name, const char* gender, int age, const char* work, int income, const char* purpose)
{
	man* new_man = new man;
	new_man->age = age;
	strcpy_s(new_man->name, name);
	strcpy_s(new_man->name, name);
	strcpy_s(new_man->gender, gender);
	strcpy_s(new_man->work, work);
	new_man->income = income;
	strcpy_s(new_man->purpose, purpose);
	enqueue(q, *new_man);
}

void enqueue(queue& q, man m)
{
	elem* newel = new elem;
	newel->value = m;
	if (!q.tail)
	{
		q.head = q.tail = newel;
	}
	else
	{
		q.tail->next = newel;
		q.tail = newel;
	}
	q.lenght++;
}
void delete_elem(queue& q)
{
	elem* rem = q.head;
	q.head = q.head->next;
	delete rem;
	q.lenght--;
}



bool dequeue(queue& q, man& m)
{
	if (!q.head)
		return false;
	m = q.head->value;
	delete_elem(q);
	if (!q.head) q.tail = nullptr;
	return true;
}

void clear(queue& q)
{
	while (q.head)
	{
		delete_elem(q);
	}
	q.tail = nullptr;
}