#include <iostream>

using namespace std;

int get_min_index(int arr[], int size, int i)
{
    int min = 99999, index = -1;
    for (; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = get_min_index(arr, size, i);
        int temp = arr[i];       
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}