#pragma once
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cmath>
#define HASH_TABLE_SIZE 5


using namespace std;

template <typename KeyType, typename ValueType>

class Map
{
    struct HashNode
    {
        KeyType _key;
        ValueType _value;
        HashNode *_next;
        int index;

        HashNode(const KeyType &key, const ValueType &value)
        {
            _key = key;
            _value = value;
            _next = nullptr;
        }
    };

    ValueType hashTable[HASH_TABLE_SIZE];
    HashNode *head;
    HashNode *prev;

public:
    Map();
    ~Map();

    void insert(const KeyType &key, const ValueType &value);
    void remove(const KeyType &key);

    void printMap();
    void printValues();
    bool isEmpty();
    ValueType &operator()(const KeyType &key);
};
int hashfunc(int key);
int hashfunc(string key);

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map()
{
    this->head = nullptr;
    this->prev = nullptr;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map()
{
    prev = head;
    while (head != nullptr)
    {
        prev = head->_next;
        delete head;
        head = prev;
    }
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::isEmpty()
{
    if (this->head == nullptr && this->prev == nullptr)
        return true;
    else
        return false;
}

template <typename KeyType, typename ValueType>
ValueType &Map<KeyType, ValueType>::operator()(const KeyType &key)
{
    prev = head;

    while (prev != nullptr && prev->_key != key)
    {
        prev = prev->_next;
    }
    if (prev->_key == key)
    {
        return hashTable[HASH_TABLE_SIZE];
    }
    else
    {
        cerr << "Something goes wrong";
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value)
{
    HashNode *temp = new HashNode(key, value);
    temp->index = hashfunc(key);
  
    this->hashTable[temp->index] = temp->_value;

    if (isEmpty())
    {
        head = temp;
    }
    else
    {
        prev = head;
        while (prev->_next != nullptr)
        {
            prev = prev->_next;
        }
        prev->_next = temp;
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType &key)

{
    prev = head;
    HashNode *temp = head;
    HashNode *toBeRemoved = nullptr;

    while (prev != nullptr && prev->_key != key)
    {
        temp = prev;
        prev = prev->_next;
    }
    if (prev == nullptr)
    {
        delete toBeRemoved;
    }
    else
    {
        toBeRemoved = prev;
        prev = prev->_next;
        temp->_next = prev;
        if (toBeRemoved == head)
        {
            head = head->_next;
        }
        hashTable[toBeRemoved->index] = "";
        delete toBeRemoved;
    }
}
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::printValues()
{
    HashNode *temp = head;

    while (temp != nullptr)
    {
        cout << hashTable << " " << temp->_value << " " << endl;
        temp = temp->_next;
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::printMap()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        cout << i << ". " << hashTable[i] << endl;
    }
    cout << endl;
}

int hashfunc(string key)
{
    int hash = 0;
    int index;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % HASH_TABLE_SIZE;
    return index;
}

int hashfunc(int key)
{
    int index;
    index = key % HASH_TABLE_SIZE;
    return index;
}