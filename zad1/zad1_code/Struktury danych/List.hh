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
       
        [param in] - 
       [param out] - 
          [result] -
    */
    struct Node
    {

        Type value;
        Node *next;

        Node(Type d)
        {
            value = d;
            next = nullptr;
        }
    };
    /*Pointers to the head and tail of the list*/
    Node *head;
    Node *tail;

public:
    List();
    ~List();

    void pushBack(const Type &newElement);
    void pushFront(const Type &newElement);
    void insert(const Type &newElement /*,int index*/);
    void remove(const Type &element, int n);
    void printList();
    //Iterator begin();
    //Iterator end();
    //ConstIterator cbegin() const;
    //ConstIterator cend() const;
    Type &operator[](int index);
};
