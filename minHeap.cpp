#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <array>

#include "minheap.h"

void Heapify(HEAP *Heap, int i, int ADI)
{
    int largest = i;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    switch (ADI)
    {
    case 1:
        if (l < Heap->size && Heap->A[l].key > Heap->A[largest].key)
            largest = l;
        if (r < Heap->size && Heap->A[r].key > Heap->A[largest].key)
            largest = r;
        ;
        if (largest != i)
        {
            std::swap(Heap->A[i].key, Heap->A[largest].key);
            Heapify(Heap, largest, ADI);
        }
        break;

    case 2:
        if (l < Heap->size && Heap->a[l].key < Heap->a[smallest].key)
            smallest = l;
        if (r < Heap->size && Heap->a[r].key < Heap->a[smallest].key)
            smallest = r;
        ;
        if (smallest != i)
        {
            std::swap(Heap->a[i].key, Heap->a[smallest].key);
            Heapify(Heap, smallest, ADI);
        }
        break;
    case 3:
        if (l < Heap->size && Heap->A[l].key > Heap->A[largest].key)
            largest = l;
        if (r < Heap->size && Heap->A[r].key > Heap->A[largest].key)
            largest = r;
        ;
        if (largest != i)
        {
            std::swap(Heap->A[i].key, Heap->A[largest].key);
            Heapify(Heap, largest, ADI);
        }

        if (l < Heap->size && Heap->a[l].key < Heap->a[smallest].key)
            smallest = l;
        if (r < Heap->size && Heap->a[r].key < Heap->a[smallest].key)
            smallest = r;
        ;
        if (smallest != i)
        {
            std::swap(Heap->a[i].key, Heap->a[smallest].key);
            Heapify(Heap, smallest, ADI);
        }
        break;
    }
}

void BuildHeap(HEAP *Heap, int ADI)
{
    int start = (Heap->size / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        Heapify(Heap, i, ADI);
    }
}

void PrintHeap(HEAP *Heap, int adi)
{
    std::cout << "capacity=" << Heap->capacity << ", size=" << Heap->size << "\n";
    if (Heap->size > 0)
    {
        switch (adi)
        {
        case 1:
            std::cout << "MaxHeap:";
            for (int i = 0; i < Heap->size; ++i)
            {
                std::cout << " " << Heap->A[i].key;
                if (i != Heap->size - 1)
                    std::cout << ",";
            }
            std::cout << "\n";
            break;
        case 2:
            std::cout << "MinHeap:";
            for (int i = 0; i < Heap->size; ++i)
            {
                std::cout << " " << Heap->a[i].key;
                if (i != Heap->size - 1)
                    std::cout << ",";
            }
            std::cout << "\n";
            break;
        case 3:
            std::cout << "MaxHeap:";
            for (int i = 0; i < Heap->size; ++i)
            {
                std::cout << " " << Heap->A[i].key;
                if (i != Heap->size - 1)
                    std::cout << ",";
            }
            std::cout << "\n";

            std::cout << "MinHeap:";
            for (int i = 0; i < Heap->size; ++i)
            {
                std::cout << " " << Heap->a[i].key;
                if (i != Heap->size - 1)
                    std::cout << ",";
            }
            std::cout << "\n";
            break;
        }
    }
}

void Insertion(HEAP *Heap, int value, int adi)
{
    int oldArraySize = Heap->size;
    Heap->size = Heap->size + 1;
    ELEMENT *newArr = (ELEMENT *)malloc(Heap->size * sizeof(ELEMENT));
    ELEMENT *newArr2 = (ELEMENT *)malloc(Heap->size * sizeof(ELEMENT));

    switch (adi)
    {
    case 1:
        std::copy(Heap->A, Heap->A + std::min(oldArraySize, Heap->size), newArr);
        delete[] Heap->A;
        newArr[Heap->size - 1].key = value;
        Heap->A = newArr;
        break;
    case 2:
        std::copy(Heap->a, Heap->a + std::min(oldArraySize, Heap->size), newArr);
        delete[] Heap->a;
        newArr[Heap->size - 1].key = value;
        Heap->a = newArr;
        break;
    case 3:
        std::copy(Heap->A, Heap->A + std::min(oldArraySize, Heap->size), newArr);
        delete[] Heap->A;
        newArr[Heap->size - 1].key = value;
        Heap->A = newArr;

        std::copy(Heap->a, Heap->a + std::min(oldArraySize, Heap->size), newArr2);
        delete[] Heap->a;
        newArr2[Heap->size - 1].key = value;
        Heap->a = newArr2;
        break;
    }
}

void ExtractMax(HEAP *Heap, int adi)
{
    if (adi == 2 || Heap->size == 0)
    {
        fprintf(stderr, "Error: ExtractMax in a min heap or a null/empty heap\n");
        return;
    }

    switch (adi)
    {
    case 1:
    {
        if (Heap->size > 1)
        {
            printf("ExtractMax: %d\n", Heap->A[0].key);
            Heap->A[0].key = Heap->A[Heap->size - 1].key;
            Heap->size -= 1;
            Heapify(Heap, 0, adi);
        }
        break;
    }
    case 2:
    {
        int maxElementIndex = FindMaxElement(Heap->a, Heap->size);
        printf("ExtractMax: %d\n", Heap->a[maxElementIndex].key);
        MinHeapDeleteElement(Heap, maxElementIndex);
        Heap->size -= 1;
        break;
    }
    case 3:
    {
        printf("ExtractMax: %d\n", Heap->A[0].key);
        Heap->A[0].key = Heap->A[Heap->size - 1].key;
        Heapify(Heap, 0, adi);
        int maxElementIndex = FindMaxElement(Heap->a, Heap->size);
        MinHeapDeleteElement(Heap, maxElementIndex);
        Heap->size -= 1;
        break;
    }
    }
}

void ExtractMin(HEAP *Heap, int adi)
{
    if (adi == 1 || Heap->size == 0)
    {
        fprintf(stderr, "Error: ExtractMin in a max heap or a null/empty heap\n");
        return;
    }

    switch (adi)
    {
    case 1:
    {
        if (Heap->size > 1)
        {
            int minElementIndex = FindMinElement(Heap->A, Heap->size);
            printf("ExtractMin: %d\n", Heap->A[minElementIndex].key);
            MaxHeapDeleteElement(Heap, minElementIndex);
            Heap->size -= 1;
        }
        break;
    }
    case 2:
    {
        printf("ExtractMin: %d\n", Heap->a[0].key);
        Heap->a[0].key = Heap->a[Heap->size - 1].key;
        Heap->size -= 1;
        Heapify(Heap, 0, adi);
        break;
    }
    case 3:
    {
        int minElementIndex = FindMinElement(Heap->A, Heap->size);
        printf("ExtractMin: %d\n", Heap->A[minElementIndex].key);
        MaxHeapDeleteElement(Heap, minElementIndex);
        Heap->a[0].key = Heap->a[Heap->size - 1].key;
        Heapify(Heap, 0, adi);
        Heap->size -= 1;
        break;
    }
    }
}

void MinHeapDeleteMin(HEAP *Heap)
{
    if (Heap->size != 0)
    {
        int lastElement = Heap->a[Heap->size - 1].key;

        Heap->a[0].key = lastElement;
        Heapify(Heap, 0, 2);
    }
}

void MinHeapDeleteElement(HEAP *Heap, int index)
{
    Heap->a[index].key = Heap->a[0].key - 1;

    int curr = index;
    while (curr > 0 && Heap->a[(curr - 1) / 2].key > Heap->a[curr].key)
    {
        int temp = Heap->a[(curr - 1) / 2].key;
        Heap->a[(curr - 1) / 2].key = Heap->a[curr].key;
        Heap->a[curr].key = temp;
        curr = (curr - 1) / 2;
    }
    MinHeapDeleteMin(Heap);
}

int FindMaxElement(ELEMENT *array, int size)
{
    int elementNumb;
    int maxNumb = -9999;
    for (int i = 0; i < size; i++)
    {
        if (array[i].key > maxNumb)
        {
            maxNumb = array[i].key;
            elementNumb = i;
        }
    }
    return elementNumb;
}

int FindMinElement(ELEMENT *array, int size)
{
    int elementNumb;
    int minNumb = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (array[i].key < minNumb)
        {
            minNumb = array[i].key;
            elementNumb = i;
        }
    }
    return elementNumb;
}

void DecreaseKey(HEAP *Heap, int position, int newKey, int adi)
{

    if (adi == 1 || Heap->size == 0)
    {
        fprintf(stderr, "Error: DecreaseKey in a max heap or a null/empty heap\n");
        return;
    }
    else if (Heap->size < position - 1 || Heap->a[position - 1].key <= newKey)
    {
        fprintf(stderr, "Error: Invalid position or newKey in DecreaseKey\n");
        return;
    }

    switch (adi)
    {
    case 2:
        Heap->a[position - 1].key = newKey;
        break;
    case 3:
        int oldKey = Heap->a[position - 1].key;
        Heap->a[position - 1].key = newKey;

        int location = 0;
        for (int i = 0; i < Heap->size; i++)
        {
            if (Heap->A[i].key == oldKey)
            {
                location = i;
            }
        }
        Heap->A[location].key = newKey;
        break;
    }
}

void IncreaseKey(HEAP *Heap, int position, int newKey, int adi)
{

    if (adi == 2 || Heap->size == 0)
    {
        fprintf(stderr, "Error: IncreaseKey in a min heap or a null/empty heap\n");
        return;
    }
    else if (Heap->size < position - 1 || Heap->A[position - 1].key >= newKey)
    {
        fprintf(stderr, "Error: Invalid position or newKey in IncreaseKey\n");
        return;
    }

    switch (adi)
    {
    case 1:
        Heap->A[position - 1].key = newKey;
        break;
    case 3:
        int oldKey = Heap->A[position - 1].key;
        Heap->A[position - 1].key = newKey;

        int location = 0;
        for (int i = 0; i < Heap->size; i++)
        {
            if (Heap->a[i].key == oldKey)
            {
                location = i;
            }
        }
        Heap->a[location].key = newKey;

        break;
    }
}
