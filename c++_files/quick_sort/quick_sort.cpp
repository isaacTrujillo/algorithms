#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *arr, int left, int right)
{
    int temp = *(arr + left);
    *(arr + left) = *(arr + right);
    *(arr + right) = temp;
}

int sort(int *arr, int start, int pivot)
{
    int left = start;
    int right = start;
    while (right < pivot)
    {
        if (*(arr + right) <= *(arr + pivot))
        {
            swap(arr, left++, right++);
        }
        else
        {
            right++;
        }
    }
    swap(arr, left, pivot);
    return left;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = sort(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << ", ";
    }
}

int main()
{
    int arrSize = sizeof(int) * 10;
    int *arr = (int *)malloc(arrSize);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 9;
    arr[4] = 78;
    arr[5] = 99;
    arr[6] = 13;
    arr[7] = 12;
    arr[8] = 22;
    arr[9] = 6;
    quickSort(arr, 0, (arrSize / sizeof(*arr)) - 1);
    printArr(arr, (arrSize / sizeof(*arr)));
    return 0;
}