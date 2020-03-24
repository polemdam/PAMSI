#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename Type>
class Stack
{
    struct StackNode
    {
        Type value;
        StackNode *next;

        StackNode(Type d)
        {
            value = d;
            next = nullptr;
        }
    };
    StackNode *head;

public:
    Stack();  
    ~Stack(); 

    void push(const Type &newElement); 
    void pop();                        
    void printStack();
    Type top();
};

template <typename Type>
Stack<Type>::Stack()
{
    head = nullptr;
}

template <typename Type>
Stack<Type>::~Stack()
{
    delete head;
}

template <typename Type>
void Stack<Type>::push(const Type &newElement)
{
    StackNode *temp = new StackNode(newElement);
    temp->next = this->head;
    this->head = temp;
   
}

template <typename Type>
void Stack<Type>::pop()
{
    if (this->head == NULL)
    {
        return; 
    } 
        StackNode *temp = this->head;
        this->head = this->head->next;
        delete (temp);
        return;
    
}
    template <typename Type>
    Type Stack<Type>::top()
    {
        return this->head->value;
    }

    template <typename Type>
    void Stack<Type>::printStack()
    {
        StackNode *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
