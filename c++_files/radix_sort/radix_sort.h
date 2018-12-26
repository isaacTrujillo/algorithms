#include <iostream>
#include <algorithm>

#define BASE 10

using namespace std;

void counting_sort(int arr[], int size, int exp)
{
    int output[size], count[BASE+1] = {0}, i;
    for(i = 0; i < size; i++) {
        count[(arr[i] / exp) % BASE]++;
    }
    for(i = 1; i <= BASE; i++) {
        count[i] += count[i-1];
    }
    for(i = size - 1 ; i > 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }
    for(i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int size)
{
    int max = *max_element(arr,arr+size);
    for(int exp = 1; (max / exp) > 0; exp *= BASE) {
        counting_sort(arr, size, exp);
    }
}