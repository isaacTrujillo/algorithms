#include <iostream>
#define BASE 10

using namespace std;

void counting_sort(int arr[], int size)
{
    int output[size], count[BASE + 1] = {0}, i;
    for (i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (i = 1; i <= BASE; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = 0; i < size; i++)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}