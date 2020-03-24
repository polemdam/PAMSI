#pragma once
#include <cstdlib>
#include <iostream>

template <typename Type>
class Queue
{
    struct QueueNode
    {
        Type value;
        QueueNode *next;

        QueueNode(Type d)
        {
            value = d;
            next = nullptr;
        }
    };
   
    QueueNode *front;
    QueueNode *back;

public:
    Queue();
    ~Queue();
    void enqueue(const Type &newElement);
    void dequeue();
    void printQueue();
};

template <typename Type>
Queue<Type>::Queue()
{
    front = nullptr;
    back = nullptr;
}

template <typename Type>
Queue<Type>::~Queue()
{
    QueueNode *temp = front;
    while (temp != back)
    {                       
        front = temp->next; 
        delete temp;      
        temp = front;       
    }
    delete back; 
}
template <typename Type>
void Queue<Type>::enqueue(const Type &newElement)
{
    if (front == nullptr)
    {
        QueueNode *temp = new QueueNode(newElement);
        temp->next = this->front;
        this->front = temp;

        return;
    }
    else
    {
        QueueNode *temp = new QueueNode(newElement);
        QueueNode *ptr = this->front;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
template <typename Type>
void Queue<Type>::dequeue()
{
    if (this->front == NULL)
    {
        return;
    }
    QueueNode *temp = this->front;
    this->front = this->front->next;
    delete (temp);
    return;
}
template <typename Type>
void Queue<Type>::printQueue()
{
    QueueNode *ptr = front;
    while (ptr != nullptr)
    {
        std::cout << ptr->value << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
