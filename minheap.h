// #include "minheap.h"

typedef struct TAG_ELEMENT
{
    int key;
} ELEMENT;

typedef struct TAG_HEAP
{
    int capacity;
    int size;
    ELEMENT *A;  //Max heap
    ELEMENT *a;  //min heap
} HEAP;

void Heapify(HEAP *Heap, int i, int ADI);
void BuildHeap(HEAP *Heap, int ADI);
int FindMaxElement(ELEMENT *array, int size);
void PrintHeap(HEAP *Heap, int adi);
void Insertion(HEAP *Heap, int value, int ADI);

void ExtractMax(HEAP *Heap, int ADI);
void ExtractMin(HEAP *Heap, int ADI);

void IncreaseKey(HEAP *Heap, int position, int newKey, int ADI);
void DecreaseKey(HEAP *Heap, int position, int newKey, int adi);

int FindMinElement(ELEMENT *array, int size);
void MinHeapDeleteElement(HEAP *Heap, int index);
void MinHeapDeleteMin(HEAP *Heap);