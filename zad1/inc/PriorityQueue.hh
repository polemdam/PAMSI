#pragma once
#include <cstdlib>
#include <iostream>

template <typename Type>
class PriorityQueue
{

    struct PriorQueueNode
    {
        Type value;
        PriorQueueNode *next;
        int prior;

        PriorQueueNode(Type d)
        {
            value = d;
            next = nullptr;
            prior = 0;
        }
    };
    
    PriorQueueNode *front;
    PriorQueueNode *back;

public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(const Type &newElement, int priority);
    void dequeue();
    void printPriorityQueue();
};

template <typename Type>
PriorityQueue<Type>::PriorityQueue()
{
    front = nullptr;
    back = nullptr;
}

template <typename Type>
PriorityQueue<Type>::~PriorityQueue()
{
    PriorQueueNode *temp = front;
    while (temp != back)
    {                       
        front = temp->next; 
        delete temp;        
        temp = front;       
    }
    delete back;

}

template <typename Type>
void PriorityQueue<Type>::enqueue(const Type &newElement, int priority)
{
    PriorQueueNode *temp = new PriorQueueNode(newElement);
    temp->value = newElement;
    temp->prior = priority;

    if (front == nullptr || priority < front->prior)
    {
        temp->next = this->front;
        this->front = temp;

        return;
    }

    else
    {
        PriorQueueNode *ptr = this->front;
        while (ptr->next != NULL && ptr->next->prior <= priority)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

template<typename Type>
void PriorityQueue<Type>::dequeue()
{
    if (this->front == NULL)
    {
        return;
    }
    PriorQueueNode *temp = this->front;
    this->front = this->front->next;
    delete (temp);
    return;
}
template<typename Type>
void PriorityQueue<Type>::printPriorityQueue()
{
    PriorQueueNode *ptr = front;
    while (ptr != nullptr)
    {
        std::cout <<"Value "<< ptr->value << " with priority " << ptr->prior << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}


