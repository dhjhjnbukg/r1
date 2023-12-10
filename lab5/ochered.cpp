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

//������������ �������
struct Queue
{
    Node* front; //������ ����
    Node* rear;  //���������

    //������������� ��������� ��������
    Queue() : front(nullptr), rear(nullptr) {}
};

//���������� �������� � �������
void enqueue(Queue* queue, int value)
{
    Node* newNode = new Node(value);
    if (!queue->front)
    {
        //���� ������, ����� ���� ���������� � ������ � ���������
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        //��������� ����� ���� � �����
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


//�������� �������� �� ������ � ������� ��������
int dequeue(Queue* queue)
{
    if (!queue->front)
    {
        //���������� -1 � ������ ���� ������� ������
        std::cerr << "ochered pustaya" << std::endl;
        return -1;
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    delete temp;
    //��������� rear ���� ����� �������� front=nullptr
    if (!queue->front)
    {
        queue->rear = nullptr;
    }
    return value;
}

//���������, ������ �� �������
bool isEmpty(Queue* queue)
{
    return !queue->front;
}


//���� enqueue
void test1()
{
    Queue myQueue;
    assert(isEmpty(&myQueue));
    enqueue(&myQueue, 10);
    assert(!isEmpty(&myQueue));
}

//���� dequeue
void test2()
{
    Queue myQueue;
    assert(isEmpty(&myQueue));
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    assert(dequeue(&myQueue) == 10);
    assert(!isEmpty(&myQueue));
    assert(dequeue(&myQueue) == 20);
    assert(isEmpty(&myQueue));
    //��������� dequeue �� ������ �������
    assert(dequeue(&myQueue) == -1);
}

//��������� isempty
void test3()
{
    Queue myQueue;
    assert(isEmpty(&myQueue));
    enqueue(&myQueue, 10);
    assert(!isEmpty(&myQueue));
    dequeue(&myQueue);
    assert(isEmpty(&myQueue));
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}