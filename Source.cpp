#include <iostream>
#include<fstream>
#include "queue.h"
using namespace std;
void load_data(const char* filename, const char* filename1, const char* filename2, queue& kredit, queue& vklad);
void show_queue(queue& q);

void main()
{
	setlocale(LC_ALL, "Rus");
	queue kredit;
	queue vklad;
	load_data("queue.txt", "kredit.txt", "vklad.txt", kredit, vklad);
	cout << "Кредит : \n";
	show_queue(kredit);
	cout << "Вклад : \n";
	show_queue(vklad);

}


void load_data(const char* filename, const char* filename1, const char* filename2, queue& kredit, queue& vklad)
{
	ifstream f(filename);
	ofstream fo1(filename1);
	ofstream fo2(filename2);
	if (f.is_open() && fo1.is_open() && fo2.is_open())
	{
		while (!f.eof())
		{
			char* man = new char[150];
			f.getline(man, 100);
			char* name = new char[50];//переменная для фио			
			char* gender = new char[8];//переменная для 
			int age;
			char* work = new char[50];
			int income;                  //заводим переменную возраст
			char* purpose = new char[10];
			sscanf_s(man, "%s%s%d%s%d%s", name, 15, gender, 10, &age, work, 50, &income, purpose, 10);//считываем данные из строчки 
			char p1[] = { "Кредит" };
			char p2[] = { "Вклад" };
			if (strcmp(purpose, p2)) {
				enqueue(vklad, name, gender, age, work, income, purpose);//добавляем данныев очередь
				fo1 << name << " " << gender << " " << age << " " << work << " " << income << " " << purpose << endl;

			}
			else if (strcmp(purpose, p1)) {
				enqueue(kredit, name, gender, age, work, income, purpose);
				fo2 << name << " " << gender << " " << age << " " << work << " " << income << " " << purpose << endl;
			}
		}
		f.close();
		fo1.close();
		fo2.close();
	}
	else
		cout << "Файл не удалось прочитать:(";
}

void show_queue(queue& q)
{
	int i = 0;//счетчик для нумерации к записяи
	while (true)
	{
		man m;//создаем переменную
		if (dequeue(q, m))//пока есть элементы в очереди    функция еникьюудаляет элемент из очереди после вывода на экран
		{
			cout << ++i << ".\t" << m.name << m.gender << "\t Возраст:" << m.age << m.work << m.income << m.purpose << endl;
		}
		else
		{
			cout << "___________";
			break;
		}
	}
}