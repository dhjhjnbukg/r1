#include <iostream>
#include <cassert>

//структура позволяюзая представлять в списке узел
struct Node
{

    int data;
    Node* next;
    //конструктор, делающий создание узла удобнее
    Node(int value) : data(value), next(nullptr) {}
};

//структура односвязного списка
struct LinkedList
{
    Node* first; //создаем указатель на певый узел
    Node* last;  //на последний
    int count;   //кол-во узлов
    //инициализация значений в начале
    LinkedList() : first(nullptr), last(nullptr), count(0) {}
};

//структура, представляющая результат поиска узла
struct FindNodeResult
{
    Node* node;
    Node* previousNode;
    FindNodeResult(Node* n, Node* prev) : node(n), previousNode(prev) {}
};

// Функция для добавления нового узла после заданного узла
//функция, позволяющая добавить новый ущел после заданного
Node* insertAfter(LinkedList* list, Node* node, int value)
{
    Node* newNode = new Node(value);
    if (!node)
    {
        //если узел, который задан не укащан, добавляем в начало
        newNode->next = list->first;
        list->first = newNode;
        if (!list->last)
        {
            //обновляем ласт если список пуст
            list->last = newNode;
        }
    }
    else
    {
        //вставка нового узла после заданного
        newNode->next = node->next;
        node->next = newNode;
        if (node == list->last)
        {
            list->last = newNode;
        }
    }

    list->count++;
    return newNode;
}


//функия, позволяющая найти узел в списке по значению
FindNodeResult find(LinkedList* list, int value)
{
    Node* current = list->first;
    Node* previous = nullptr;
    while (current && current->data != value)
    {
        previous = current;
        current = current->next;
    }
    return FindNodeResult(current, previous);
}

//функция, удаляющая узел после заданного
void removeAfter(LinkedList* list, Node* node)
{
    if (!node)
    {
        if (list->first)
        {
            Node* temp = list->first;
            list->first = list->first->next;
            delete temp;

            if (!list->first)
            {
                list->last = nullptr;
            }

            list->count--;
        }
    }
    else if (node->next)
    {
        Node* temp = node->next;
        node->next = node->next->next;
        delete temp;
        if (!node->next)
        {
            list->last = node;
        }
        list->count--;
    }
}

//проверяем на отсутствие циклов
void assertNoCycles(LinkedList* list)
{
    int length = 0;
    Node* current = list->first;
    while (current)
    {
        length++;
        current = current->next;
        assert(length <= list->count && "Cycle detected in the linked list.");
    }
}