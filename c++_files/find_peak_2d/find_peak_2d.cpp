#include <iostream>
#define MAX1D 8
#define MAX2D 20

using namespace std;

struct peak2d{
    int i;
    int j;
};

struct peak2d findPeak(int arr[MAX1D][MAX2D], int floor, int top);

int findGlobalMax(int arr[MAX1D][MAX2D], int i);

main()
{
    int arr[MAX1D][MAX2D] = {
        {2, 6, 2, 5, 12, 54,  67,   43,  67,  3},
        {2, 6, 2, 5, 21, 24,  4,    56,  57,  12},
        {2, 6, 2, 5, 31, 45,  67,   23,  56,  67},
        {2, 6, 2, 5, 21, 45,  57,   678, 12,  43},
        {2, 6, 2, 5, 10, 3,   5,    7,   8,   20},
        {2, 6, 2, 5, 2,  5,   8,    1,   5,   78},
        {5, 2, 0, 7, 21, 456, 68,   2,   768, 21},
        {1, 5, 7, 2, 21, 46,  5678, 23,  78,  12}};
    struct peak2d res = findPeak(arr, 0, MAX1D);
    cout << "peak finded on arr[" << res.i << "][" << res.j << "]";
    return 0;
}
int findGlobalMax(int arr[MAX1D][MAX2D], int i)
{
    int min = 0;
    for (int j = 0; j < MAX2D; j++)
    {
        if (arr[i][j] > arr[i][min])
        {
            min = j;
        }
    }
    return min;
}
struct peak2d findPeak(int arr[MAX1D][MAX2D], int floor, int top)
{
    int index = (floor + top) / 2;
    int j = findGlobalMax(arr, index);
    if (index - 1 < floor || arr[index - 1][j] <= arr[index][j])
    {
        if (index + 1 == top || arr[index + 1][j] <= arr[index][j])
        {
            struct peak2d res = {index, j};
            return res;
        }
        else
        {
            return findPeak(arr, index, top);
        }
    }
    return findPeak(arr, floor, index);
}