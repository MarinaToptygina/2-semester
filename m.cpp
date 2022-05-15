#include "List.h"

void add(elem*& first, int data)
{
    elem* newel = new elem;// �������� ������� ���� ���������� ��������� ������ �������� ������
    newel->a = data;       //�������� � ��� ��������� ������

    if (first)

    {
        elem* curr = first;// ��������� �� ������ �������
        while (curr->next)
        {
            curr = curr->next;// ���������� ��������� �� ��������� �������
        }

        curr->next = newel;// ������������� � �������� �������� ��������� next �� ����� �������
    }
    else
    {
        first = newel;// ������ ������ �� ����. ������ ����� ������� ����� ������
    }
}

// ���������� �������� � �������� ������� � ������.
void insert(elem*& first, int data, int pos)
{
    elem* newel = new elem; // �������� �������� ������
    newel->a = data;   // ��������� �������    
    if (!first || pos <= 0)
    {
        newel->next = first;
        first = newel;
    }
    else
    {
        elem* curr = first;// ��������� �� ������� �������
        int p = 0;
        while (p < pos - 1 && curr->next)//���� ����� ������� ��� ��������
        {
            curr = curr->next;
            p++;

        }
        newel->next = curr->next;
        curr->next = newel;
    }
}

const int* get(const elem* first, int pos)
{
    if (pos < 0 || !first) return nullptr;// �������� � ����� ������� �� ����������

    elem* curr = (elem*)first;       //(elem*)-���������� ����� �� � ��������� const
    int p = 0;
    while (p < pos && curr)
    {
        curr = curr->next;
        p++;
    }

    if (curr) return &curr->a;// ������� ������. ���������� ��������� �� ��������   �������� ����� ���������� a
    return curr ? &curr->a : nullptr;// ������� �� ������
}

int count(const elem* first)
{
    int cnt = 0;
    elem* curr = (elem*)first;
    while (curr)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

bool remove(elem*& first, int pos)
{

    if (!first || pos < 0) return false;
    // ���� ��������� ������� ������ �������, ������ ��������� �� ������ ������
    if (!pos)
    {
        elem* rem = first;    //������� ��������������� ��������� �� ��������� ������� ��� �������� ��������
        first = first->next;  //�������� ��������� � ���������� �������� �� ���������
        delete rem;          //������� 
        return true;
    }

    // ������� �������, �������������� �������� � ��������� �������
    int p = 0;
    elem* curr = first;    //��������� �� ������� ������� ������
    while (p < pos - 1 && curr->next)                //����� ������� ������� ��������� ������ ������ �� ���������� ��������
    {
        curr = curr->next;
        p++;
    }
    //�� ������ ����������� ����� ��������� ���������,�� ���� ��������  ������� ������� �� ����������� �� ��������� �������� � ������ ������
    //���� ������ �� ����� ������� �����������,
    // ���������� ������� ������ �� �����:
    if (curr->next)                    //���� ���� ���� ������� ������ ���� ��� �������
    {
        elem* rem = curr->next;       //�������� ��� ��������� ������� 
        curr->next = curr->next->next;//�������� ����� ��������
        delete rem;                   // ����� �������
        return true;                  // �������� �������
    }

    return false;
}

void clear(elem*& first)
{
    while (first)
    {
        elem* rem = first;      //������� ��������� ���������
        first = first->next;
        delete rem;
    }


}