#pragma once
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <math.h>
#include <algorithm>
template <typename type, int size>
class Array
{
    type *array;

public:
    Array();
    ~Array();
    void printArray();
    void SetArray(float sort = 0);
    void merge(int beginingIndex, int centreIndex, int endIndex);
    void mergesort(int beginingIndex = 0, int endIndex = size - 1);
    void swap(type firstElem, type lastElem);
    type partition(int beginingIndex, int endIndex);
    void quicksort(int beginingIndex = 0, int endIndex = size - 1);
    void heap(int count, int i);
    void heapsort(int count = size);
    void insertionsort(int beginingIndex = 0, int endIndex = size - 1);
    void introsort_r(int beginingIndex = 0, int endIndex = size );
    void introsort(int beginingIndex = 0, int endIndex = size);
    void freeMemory();
    void MedianOfThree(int L, int R);
    bool isSorted();
};

template <typename type, int size>
Array<type, size>::Array()
{
}

template <typename type, int size>
Array<type, size>::~Array()
{
    delete array;
}

template <typename type, int size>
void Array<type, size>::merge(int beginingIndex, int centreIndex, int endIndex)
{

    int left_array_size = centreIndex - beginingIndex + 1;
    int right_array_size = endIndex - centreIndex;

    type *left_array = new type[left_array_size];
    type *right_array = new type[right_array_size];

    for (int i = 0; i < left_array_size; i++)
        left_array[i] = array[beginingIndex + i];
    for (int i = 0; i < right_array_size; i++)
        right_array[i] = array[centreIndex + 1 + i];

    int i = 0;
    int j = 0;
    int k = beginingIndex;

    while (i < left_array_size && j < right_array_size)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_array_size)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_array_size)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }
    delete[] left_array;
    delete[] right_array;
}

template <typename type, int size>
void Array<type, size>::mergesort(int beginingIndex, int endIndex)
{
    if (beginingIndex < endIndex)
    {
        int centreIndex = beginingIndex + (endIndex - beginingIndex) / 2;
        mergesort(beginingIndex, centreIndex);
        mergesort(centreIndex + 1, endIndex);
        merge(beginingIndex, centreIndex, endIndex);
    }
}
template <typename type, int size>
void Array<type, size>::SetArray(float sort)
{
    array = new type[size];
    if (array == nullptr)
        std::cerr << "Memory allocation fault" << std::endl;
    else
    {
        srand(time(NULL));
        for (unsigned int i = 0; i < size; i++)
        {
            array[i] = rand() % size + 1;
        }
        if (sort > 0)
        {
            std::sort(array, array + (int)((sort / 100) * size));
        }
        if (sort < 0)
        {
            std::sort(array, array + size);
            for (int i = 0; i < size / 2; i++)
                swap(array[i], array[size - i]);
        }
    }
}
template <typename type, int size>
void Array<type, size>::printArray()
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
template <typename type, int size>
void Array<type, size>::swap(type firstElem, type lastElem)
{
    type temp;
    temp = array[firstElem];
    array[firstElem] = array[lastElem];
    array[lastElem] = temp;
}

template <typename type, int size>
type Array<type, size>::partition(int beginingIndex, int endIndex)
{
    long i, j;
    if (endIndex >= 3)
        MedianOfThree(beginingIndex, endIndex);
    for (i = beginingIndex, j = endIndex - 2;;)
    {
        for (; array[i] < array[endIndex - 1]; ++i)
            ;
        for (; j >= endIndex && array[j] > array[endIndex - 1]; --j)
            ;
        if (i < j)
            swap(i++, j--);
        else
            break;
    }
    swap(i, endIndex - 1);
    return i;
}
template <typename type, int size>
void Array<type, size>::quicksort(int beginingIndex, int endIndex)
{
    if (beginingIndex < endIndex)
    {
        int pi = partition(beginingIndex, endIndex);
        quicksort(beginingIndex, pi - 1);
        quicksort(pi + 1, endIndex);
    }
}
template <typename type, int size>
void Array<type, size>::heap(int count, int i)

{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left<count && array[left]> array[largest])
	{
		largest = left;
	}

	if (right < count && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(i, largest);
		heap(count, largest);
	}
}

template <typename type, int size>
void Array<type, size>::heapsort(int count)
{
	for (int i = count / 2 - 1; i >= 0; i--)
	{
		heap(count, i);
	}

	for (int i = count - 1; i >= 0; i--)
	{
		swap(0, i);
		heap(i, 0);
	}
}

template <typename type, int size>
void Array<type, size>::introsort(int beginingIndex, int endIndex)
 {
    introsort_r(endIndex, (int)floor(2 * log(size)));
    insertionsort(beginingIndex, endIndex);
} 

template <typename type, int size>
void Array<type, size>::freeMemory()
{
    delete[] array;
}

template <typename type, int size>
void Array<type, size>::MedianOfThree(int L, int R)
{
    if (array[++L - 1] > array[--R])
        swap(L - 1, R);
    if (array[L - 1] > array[R / 2])
        swap(L - 1, R / 2);
    if (array[R / 2] > array[R])
        swap(R / 2, R);
    swap(R / 2, R - 1);
}

template <typename type, int size>
void Array<type, size>::insertionsort(int beginingIndex, int endIndex)
 {

    {
        long i, j;
        type temp;
        for (i = beginingIndex + 1; i < endIndex; ++i)
        {
            temp = array[i];
            for (j = i; j > 0 && temp < array[j - 1]; --j)
                array[j] = array[j - 1];
            array[j] = temp;
        }
    }
} 

 template <typename type, int size>
void Array<type, size>::introsort_r(int beginingIndex, int endIndex)

{
    long i;
    if (endIndex <= 0)
    {
        heapsort(beginingIndex);
        return;
    }
    i = partition(0, beginingIndex);
    if (i > 9)
        introsort_r(i, endIndex - 1);
    if (endIndex - 1 - i > 9)
        introsort_r(beginingIndex - 1 - i, endIndex - 1);
} 

template <typename type, int size>
bool Array<type, size>::isSorted()
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            std::cout << "Sorted " << std::endl;
            return true;
        }
    }
    return false;
}