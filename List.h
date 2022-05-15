#pragma once
struct elem
{
	int a;
	elem* next = nullptr;
};

// Функция для добавления элемента в конец списка
// каждый новый элемент добавляется последним
void add(elem*& list, int data);

// Функция для добавления элемента на указанное место в списке
void insert(elem*& list, int data, int position);

// Функция поиска элемента по его номеру (позиции) в списке
const int* get(const elem* list, int position);

// Определение количества элементов списка
int count(const elem* list);

// Функция удаления элемента по его позиции
bool remove(elem*& list, int position);

// Функция удаления списка
void clear(elem*& list);