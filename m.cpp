#include "List.h"

void add(elem*& first, int data)
{
    elem* newel = new elem;// Создание объекта типа структурыб выделение памяти элемента списка
    newel->a = data;       //записать в эту структуры данные

    if (first)

    {
        elem* curr = first;// указатель на первый элемент
        while (curr->next)
        {
            curr = curr->next;// Перемещаем указатель на следующий элемент
        }

        curr->next = newel;// устанавливаем у текущего элемента указатель next на новый элемент
    }
    else
    {
        first = newel;// Списка раньше не было. Значит новый элемент будет первым
    }
}

// Добавление элемента в заданную позицию в списке.
void insert(elem*& first, int data, int pos)
{
    elem* newel = new elem; // Создание элемента списка
    newel->a = data;   // размещаем элемент    
    if (!first || pos <= 0)
    {
        newel->next = first;
        first = newel;
    }
    else
    {
        elem* curr = first;// Указатель на текущий элемент
        int p = 0;
        while (p < pos - 1 && curr->next)//надо найти позицию для элемента
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
    if (pos < 0 || !first) return nullptr;// Элемента с таким номером не существует

    elem* curr = (elem*)first;       //(elem*)-приведение типов тк в параметре const
    int p = 0;
    while (p < pos && curr)
    {
        curr = curr->next;
        p++;
    }

    if (curr) return &curr->a;// Элемент найден. Возвращаем указатель на значение   получаем адрес переменной a
    return curr ? &curr->a : nullptr;// Элемент не найден
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
    // Если требуется удалить первый элемент, меняем указатель на начало списка
    if (!pos)
    {
        elem* rem = first;    //создаем вспомогательный указатель на удаляемый элемент для удаления элемента
        first = first->next;  //сдвигаем указатель с удаляемого элемента на следующий
        delete rem;          //удаляем 
        return true;
    }

    // Находим элемент, предшествующий элементу с указанным номером
    int p = 0;
    elem* curr = first;    //указатель на текущий элемент списка
    while (p < pos - 1 && curr->next)                //чтобы удалить элемент указатель должен стоять на предыдущем элементе
    {
        curr = curr->next;
        p++;
    }
    //мы должны остановится перед удаляемым элементом,но если значение  слишком большое то остановимся на последнем элементе и уалять нечего
    //надо понять на какой позиции остановился,
    // Определяем причину выхода из цикла:
    if (curr->next)                    //если есть след элемент значит есть что удалять
    {
        elem* rem = curr->next;       //сохраним как удаляемый элемент 
        curr->next = curr->next->next;//присвоим новое значение
        delete rem;                   // можем удалить
        return true;                  // удаление успешно
    }

    return false;
}

void clear(elem*& first)
{
    while (first)
    {
        elem* rem = first;      //создаем временный указатель
        first = first->next;
        delete rem;
    }


}