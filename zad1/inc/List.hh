#pragma once
#include <cstdlib>
#include <iostream>

template <typename Type>
class List
{
    /* Nested helper class.
       
       Characterizes a variable containing a pointer to the next value
       and a variable having the value of this element.
       
       It has a unary constructor, assigns a default value
       
        param[in] - 
       param[out] - 
           result -
    */
    struct ListNode
    {
        Type value;
        ListNode *next;

        ListNode(Type d)
        {
            value = d;
            next = nullptr;
        }
    };
    
    ListNode *head;
    ListNode *tail;

public:
    List();
    ~List();

    void pushBack(const Type &newElement);
    void pushFront(const Type &newElement);
    void insert(const Type &newElement, int index);
    void remove(int index);
    void printList();
    //Iterator begin();
    //Iterator end();
    //ConstIterator cbegin() const;
    //ConstIterator cend() const;
    Type &operator[](int index);
};

template <typename Type>
List<Type>::List()
{
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
List<Type>::~List()
{
    ListNode *temp = head;
    while (temp != tail)
    {                      
        head = temp->next; 
        delete temp;      
        temp = head;       
    }
    delete tail; 
}

template <typename Type>
void List<Type>::pushBack(const Type &newElement)
{
    if (head == nullptr)
    {
        pushFront(newElement);
        return;
    }
    ListNode *temp = new ListNode(newElement);
    ListNode *ptr = this->head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

template <typename Type>
void List<Type>::pushFront(const Type &newElement)
{
    ListNode *temp = new ListNode(newElement);
    temp->next = this->head;
    this->head = temp;
}
template <typename Type>
void List<Type>::insert(const Type &newElement, int index)
{
    ListNode *temp = new ListNode(newElement);
    if (index == 1)
    {
        temp->next = this->head;
        this->head = temp;
        return;
    }
    index--;
    ListNode *ptr = this->head;
    while (ptr != nullptr && --index)
    {
        ptr = ptr->next;
    }
    if (ptr == nullptr)
        return;
    temp->next = ptr->next;
    ptr->next = temp;
}

template <typename Type>
void List<Type>::remove(int index)
{
    ListNode *temp = head;
    ListNode *prev = nullptr;
    for (int i = 1; i < index; ++i)
    { 
        if (temp != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        else
            throw "Lista jest krótsza niż argument w remove!";
    }


    prev->next = temp->next;
    delete temp;
}

template <typename Type>
void List<Type>::printList()
{
    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        std::cout << ptr->value << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
