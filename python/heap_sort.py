def build_heap(arr):
    arrSize = len(arr)
    node = int(arrSize/2)
    while(node > 0):
        heapify(arr, node)
        node -= 1


def swap(arr, child, node):
    temp = arr[child]
    arr[child] = arr[node]
    arr[node] = temp
    heapify(arr, child+1)


def heapify(arr, node):
    arrSize = len(arr)
    leftChild = node*2
    rightChild = leftChild
    leftChild -= 1
    node -= 1
    if(rightChild < arrSize):
        if(arr[rightChild] > arr[leftChild]):
            if(arr[rightChild] > arr[node]):
                swap(arr, rightChild, node)
        else:
            if(arr[leftChild] > arr[node]):
                swap(arr, leftChild, node)
    if(leftChild < arrSize):
        if(arr[leftChild] > arr[node]):
            swap(arr, leftChild, node)


def heap_sort(arr):
    tempArr = []
    while(len(arr) != 0):
        arrSize = len(arr)
        tempArr.append(arr[0])
        temp = arr[arrSize-1]
        arr[arrSize-1] = arr[0]
        arr[0] = temp
        arr = arr[:arrSize-1]
        heapify(arr, 1)
    return tempArr


array = [0,5,10,4,1,7,2]
build_heap(array)
array = heap_sort(array)
print(array)
