def swap(arr, i, j):
    """Swaps two items on an array

    Args:
        arr: Array to be changed
        i: index of swap number
        j: index of the other swap
    """
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
    return arr

def bubble_sort(arr):
    """Sorts an array by bubble sort

    This algorithm is pretty slow since its asymptotic notation for worst case is θ(n^2)

    Args:
        arr: Array to be sorted
    """
    arr_size = len(arr)
    for i in range(arr_size):
        for j in range(arr_size-1):
            if (arr[j] > arr[j+1]):
                swap(arr,j,j+1)
    return arr

print(bubble_sort([3,6,5,8,32,56,42,76,23,5678,2,0.2,0.23,0.001]))