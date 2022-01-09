#include <iostream>
#include <math.h>

using namespace std;

void swap(int &a, int &b);
void SelectionSort(int* a, int n);
void InsertionSort(int* a, int n);
void BubbleSort(int* a, int n);
void shakerSort(int* a, int n);
void shellSort(int* a, int n);
void HeapSort(int* a, int n);
void mergeSort(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
void CountingSort(int* a, int n);
void radixSort(int* a, int n);
void FlashSort(int* a, int n);

void SelectionSortCount(int* a, int n, long long& count);
void InsertionSortCount(int* a, int n, long long& count);
void BubbleSortCount(int* a, int n, long long& count);
void shakerSortCount(int* a, int n, long long& count);
void shellSortCount(int* a, int n, long long& count);
void HeapSortCount(int* a, int n, long long& count);
void mergeSortCount(int* a, int left, int right, long long& count);
void QuickSortCount(int* a, int left, int right, long long& count);
void CountingSortCount(int* a, int n, long long& count);
void radixSortCount(int* a, int n, long long& count);
void FlashSortCount(int* a, int n, long long& count);

void print(int* a, int n);