#include <iostream>

using namespace std;

int findPeak(int arr[], int floor, int top)
{
    int index = (floor+top)/2;
    if(index-1 < floor || arr[index-1] <= arr[index]) {
        if(index+1 == top || arr[index+1] <= arr[index]) {
            return index;
        } else {
            return findPeak(arr, index, top);
        }
    }
    return findPeak(arr, floor, index);
}

main()
{
    int arr[] = {2,6,2,5,2,0,1,5,7,8,3,6,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    cout << findPeak(arr, 0, arrSize);
    return 0;
}