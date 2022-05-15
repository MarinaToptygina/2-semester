#include<iostream>
using namespace std;
#include "List.h"


// ����������� ������ �� ������
void show_list(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;//������
	else while (curr)
	{
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}


void fill_list(elem*& list)//�������� � ���������� ������
{
	int n;
	cout << "������� ������ ������: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "������� ��������  : ";
		int a;
		cin >> a;
		add(list, a);
	}
}

bool find(elem* list, int t)//�������� �� ������������ 
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
	else cout << "�������� �� ���������" << endl;
}
void unik_insert(elem*& list, int t, int p)
{
	if (find(list, t))	insert(list, t, p);
	else cout << "�������� �� ���������" << endl;
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

void fill_list1(elem*& list)//���������� ��������
{
	char* data = new char[50];
	int t, p;
	cout << "������� ��������, ������� ������ �������� ���";
	cout << " �������� � ����� ������� ��� ������� ����� ������";
	cout << endl;
	cin.ignore();//����� cin.getline ����� sscanf_s �� ����� ��������	
	cin.getline(data, 50);//���� ������ cin,�� ��������� ������ �� �������	

	int k = sscanf_s(data, "%d %d", &t, &p);
	switch (k)
	{
	case 1:
	{
		unik_add(list, t);// ���� ������ ��������, ��������� ��� � ������
		break;
	}
	case 2:
	{
		unik_insert(list, t, p);// ���� � ��������, � ��� �������// ��������� ������� �� ��������� �����			
	}
	}
	delete[] data;
}

void main()
{
	setlocale(LC_ALL, "ru");
	elem* list1 = nullptr;  // ��������� �� ������ ������ (���������� ����)

	fill_list(list1);
	show_list(list1);
	remov_identical_elements(list1);
	fill_list1(list1);
	show_list(list1);
}