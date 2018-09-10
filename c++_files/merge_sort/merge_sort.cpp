#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int arr[], int floor, int mid, int top){
    int sizeLow = mid-floor+1;
    int sizeHigh = top-mid; 
    int lowHalf[sizeLow];
    int highHalf[sizeHigh];
    int i,j;
    for (i = 0; i < sizeLow; i++)
        lowHalf[i] = arr[floor + i];
    for (j = 0; j < sizeHigh; j++)
        highHalf[j] = arr[mid + 1 + j];
    int k = 0;
    i=0;
    j=0;
    while(i < sizeLow && j < sizeHigh) {
        if(lowHalf[i] <= highHalf[j]) {
            arr[k] = lowHalf[i++];
        }else {
            arr[k] = highHalf[j++];
        }
        k++;
    }

    while( i < sizeLow) {
        arr[k] = lowHalf[i];
        i++;
        k++;
    }
    while(j < sizeHigh) {
        arr[k] = highHalf[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int floor, int top) {
    if(floor < top) {   
        int mid = floor+(top-floor)/2;
        mergeSort(arr, floor, mid);
        mergeSort(arr, mid+1, top);
        merge(arr, floor, mid, top);
    }
}

int main() {
    int arr[] = {3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i = 0 ; i < size; i++) {
        cout << arr[i] << ", ";
    }
}