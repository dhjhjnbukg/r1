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

//представляем очередь
struct Queue
{
    Node* front; //первый узел
    Node* rear;  //последний

    //инициализация начальных значениц
    Queue() : front(nullptr), rear(nullptr) {}
};

//добавление элемента в очередь
void enqueue(Queue* queue, int value)
{
    Node* newNode = new Node(value);
    if (!queue->front)
    {
        //если пустая, новый узел становится и первым и последним
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        //добавляем новый узел в конец
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


//удаление элемента из начала и возврат значения
int dequeue(Queue* queue)
{
    if (!queue->front)
    {
        //возвращаем -1 в случае если очередь пустая
        std::cerr << "ochered pustaya" << std::endl;
        return -1;
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    delete temp;
    //обновляем rear если после удаления front=nullptr
    if (!queue->front)
    {
        queue->rear = nullptr;
    }
    return value;
}

//проверяем, пустая ли очередь
bool isEmpty(Queue* queue)
{
    return !queue->front;
}


//тест enqueue
void test1()
{
    Queue myQueue;
    assert(isEmpty(&myQueue));
    enqueue(&myQueue, 10);
    assert(!isEmpty(&myQueue));
}

//тест dequeue
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
    //проверяем dequeue из пустой очереди
    assert(dequeue(&myQueue) == -1);
}

//проверяем isempty
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