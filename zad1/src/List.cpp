/* #pragma once
#include <cstdlib>
#include <iostream>

template <typename Type>
class List
{
     Nested helper class.
       
       Characterizes a variable containing a pointer to the next value
       and a variable having the value of this element.
       
       It has a unary constructor, assigns a default value
       
        param[in] - 
       param[out] - 
           result -
    
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
    Pointers to the head and tail of the list
    Node *head;
    Node *tail;

public:
    List();
    ~List();

    // void pushBack(const Type &newElement);
    //void pushFront(const Type &newElement);
    void insert(const Type &newElement ,int index);
    void remove(const Type &element, int n);
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
    Node *temp = head;
    while (temp != tail)
    {                      // Do momentu kiedy nie natrafimy na ogon.
        head = temp->next; // Podmieniamy head na następny element.
        delete temp;       // Usuwamy węzeł, na który wskazuje zmienna pomocnicza.
        temp = head;       // Idziemy dalej aż nie natrafimy na ogon.
    }
    delete tail; // Usuwamy węzeł, na który wskazuje ogon.
}

template <typename Type>
void List<Type>::insert(const Type &newElement ,int index)
{
    if (head != nullptr)
    { // W przypadku gdy mamy jakieś elementy w liście.
        Node *temp = new Node(newElement);
        if (temp == nullptr)
            throw "Błąd alokacji pamięci, przy dodawaniu elementu do listy!";
        tail->next = temp;
        tail = temp;
    }
    else
    {
        head = new Node(newElement);
        tail = head;
    }
}

template <typename Type>
void List<Type>::remove(const Type &element, int n)
{
    element = head;
    Node *prev = nullptr;
    for (int i = 0; i < n; ++i)
    { // W pętli będziemy szukać elementu do usuniecia.
        if (element != nullptr)
        {
            prev = element;
            element = element->next;
        }
        else
            throw "Lista jest krótsza niż argument w remove!";
    }

    // Przepinamy tutaj wskaźnik do następnego elementu poprzedniego rekordu listy
    // na ten, na który wskazywał element, który mamy usunąć
    // następnie go usuwamy.
    prev->next = element->next;
    delete element;
}

template <typename Type>
void List<Type>::printList()
{
    Node *i = head;
    while (i != nullptr)
    {
        std::cout << i->wartosc << " ";
        i = i->next;
    }
    std::cout << std::endl;
}
 */