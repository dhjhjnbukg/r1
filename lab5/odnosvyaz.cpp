#include <iostream>
#include <cassert>

//��������� ����������� ������������ � ������ ����
struct Node
{

    int data;
    Node* next;
    //�����������, �������� �������� ���� �������
    Node(int value) : data(value), next(nullptr) {}
};

//��������� ������������ ������
struct LinkedList
{
    Node* first; //������� ��������� �� ����� ����
    Node* last;  //�� ���������
    int count;   //���-�� �����
    //������������� �������� � ������
    LinkedList() : first(nullptr), last(nullptr), count(0) {}
};

//���������, �������������� ��������� ������ ����
struct FindNodeResult
{
    Node* node;
    Node* previousNode;
    FindNodeResult(Node* n, Node* prev) : node(n), previousNode(prev) {}
};

// ������� ��� ���������� ������ ���� ����� ��������� ����
//�������, ����������� �������� ����� ���� ����� ���������
Node* insertAfter(LinkedList* list, Node* node, int value)
{
    Node* newNode = new Node(value);
    if (!node)
    {
        //���� ����, ������� ����� �� ������, ��������� � ������
        newNode->next = list->first;
        list->first = newNode;
        if (!list->last)
        {
            //��������� ���� ���� ������ ����
            list->last = newNode;
        }
    }
    else
    {
        //������� ������ ���� ����� ���������
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


//������, ����������� ����� ���� � ������ �� ��������
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

//�������, ��������� ���� ����� ���������
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

//��������� �� ���������� ������
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