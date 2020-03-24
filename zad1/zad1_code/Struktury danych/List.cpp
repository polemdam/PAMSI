#include <iostream>
#include "List.hh"

using namespace std;

template <typename Type>
List<Type>::List() {
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
List<Type>::~List() {
    Node* temp = head;
        while (temp != tail) {    // Do momentu kiedy nie natrafimy na ogon.
            head = temp->next;    // Podmieniamy head na następny element.
            delete temp;          // Usuwamy węzeł, na który wskazuje zmienna pomocnicza.
            temp = head;          // Idziemy dalej aż nie natrafimy na ogon.
	}
    delete tail;                  // Usuwamy węzeł, na który wskazuje ogon.
}

template <typename Type>
void List<Type>::insert(const Type &newElement /*,int index*/){
    if (head != nullptr) {        // W przypadku gdy mamy jakieś elementy w liście.
        Node* temp = new Node(newElement);
        if (temp == nullptr) 
            throw "Błąd alokacji pamięci, przy dodawaniu elementu do listy!";
        tail->next = temp;
        tail = temp;
    }
    else {
        head = new Node(newElement);
        tail = head;
    }
}

template <typename Type>
void List<Type>::remove(const Type &element, int n) {
    element = head;
    Node* prev = nullptr;
        for (int i=0; i<n; ++i){  // W pętli będziemy szukać elementu do usuniecia.
            if (element != nullptr) {
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
void List<Type>::printList() {
    Node* i = head;
    while (i!=nullptr) {
        std::cout << i->wartosc << " ";
        i=i->next;
    }
    std::cout << std::endl;
}
