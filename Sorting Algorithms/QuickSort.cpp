#include <iostream>

const int n = 8;

// 划分操作，将表a[low...high]划分为满足条件的两个子表
int Partition(int a[], int low, int high)
{
    int pivot = a[low]; // 将表中第一个元素设为枢纽，对表进行划分
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high]; // 将比枢纽小的元素移动到左端
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low]; // 将比枢纽大的元素移动到右端
    }
    a[low] = pivot; // 枢纽元素存放到最终位置
    return low; // 返回存放枢纽的最终位置q
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotops = Partition(a, low, high); // 划分
        // 依次对两个子表进行递归排序
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
    QuickSort(a, 0, n - 1); // low为第一位，high为最后一位
    printArray(a, n);
    return 0;
}