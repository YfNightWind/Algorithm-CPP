#include <iostream>

const int n = 8;

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotops = Partition(a, low, high);
        QuickSort(a, low, pivotops - 1);
        QuickSort(a, pivotops + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[n] = {6, 5, 3, 1, 8, 7, 2, 4};
    QuickSort(a, 0, n - 1); // low为第一位, high为最后一位
    printArray(a, n);
    return 0;
}