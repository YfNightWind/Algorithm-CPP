#include <iostream>

const int n = 8;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;              // 表示本趟冒泡是否发生交换标志
        for (int j = n - 1; j > i; j--) // 一趟冒泡过程
        {
            if (a[j - 1] > a[j])      // 若为逆序
                swap(a[j - 1], a[j]); // 交换
            flag = true;
        }
        if (flag == false)
            return; // 本趟遍历后没有发生交换，说明表已经有序
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
    BubbleSort(a, n);
    printArray(a, n); // 1 2 3 4 5 6 7 8
    return 0;
}