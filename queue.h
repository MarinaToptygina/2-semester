#pragma once
struct man
{
	char name[50];
	char gender[8];
	int age;
	char work[50];
	int income;
	char purpose[10];
};

struct elem
{
	man value;
	elem* next = nullptr;
};

struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t lenght = 0;
};

void enqueue(queue& q, const char* name, const char* gender, int age, const char* work, int income, const char* purpose);
void enqueue(queue& q, man m);
bool dequeue(queue& q, man& m);
void clear(queue& q);
