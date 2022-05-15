#include<iostream>
using namespace std;
#include "List.h"


// ќтображение списка на экране
void show_list(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;//пустой
	else while (curr)
	{
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}


void fill_list(elem*& list)//создание и заполнение списка
{
	int n;
	cout << "¬ведите размер списка: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "¬ведите значение  : ";
		int a;
		cin >> a;
		add(list, a);
	}
}

bool find(elem* list, int t)//проверка на уникальность 
{
	elem* curr = list;

	while (curr)
	{
		if (curr->a == t)
		{
			return false;
		}
		curr = curr->next;
	}
	return true;
}

void unik_add(elem*& list, int t)
{
	if (find(list, t)) add(list, t);
	else cout << "«начение не уникально" << endl;
}
void unik_insert(elem*& list, int t, int p)
{
	if (find(list, t))	insert(list, t, p);
	else cout << "«начение не уникально" << endl;
}

void remov_identical_elements(elem*& list)
{
	int cnt = count(list);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			int a_i = *get(list, i);
			int a_j = *get(list, j);
			if (i != j) {
				if (a_i == a_j) {
					remove(list, j);
					cnt--;
				}
			}
		}
	}
}

void fill_list1(elem*& list)//добавление элемента
{
	char* data = new char[50];
	int t, p;
	cout << "¬ведите значение, которое хотите добавить или";
	cout << " значение и номер позиции дл€ вставки через пробел";
	cout << endl;
	cin.ignore();//иначе cin.getline перед sscanf_s не хочет работать	
	cin.getline(data, 50);//если просто cin,то считывает только до пробела	

	int k = sscanf_s(data, "%d %d", &t, &p);
	switch (k)
	{
	case 1:
	{
		unik_add(list, t);// ≈сть только значение, добавл€ем его в список
		break;
	}
	case 2:
	{
		unik_insert(list, t, p);// ≈сть и значение, и его позици€// ¬ставл€ем элемент на указанное место			
	}
	}
	delete[] data;
}

void main()
{
	setlocale(LC_ALL, "ru");
	elem* list1 = nullptr;  // ”казатель на начало списка (изначально пуст)

	fill_list(list1);
	show_list(list1);
	remov_identical_elements(list1);
	fill_list1(list1);
	show_list(list1);
}