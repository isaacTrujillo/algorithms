int* counting_sort(int arr[], int size, int range)
{
    int *out_arr;
    int count_arr[range + 1] = {0}, i;
    out_arr = (int *)malloc(size);

    for(i = 0; i < size; i++) {
        count_arr[arr[i]]++;
    }
    for(i = 1; i <= range; i++) {
        count_arr[i] += count_arr[i-1];
    }
    for(i = 0; i < size; i++) {
        out_arr[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]--;
    }
    return out_arr;
}