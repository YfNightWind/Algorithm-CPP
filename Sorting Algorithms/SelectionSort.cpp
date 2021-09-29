//
//  QuickSort.cpp
//  Algorithm
//
//  Created by Alex Lin on 2021/9/25.
//

// #include <bits/stdc++.h> if you're using gcc, then use this header
#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int nums[], int n)
{
    int temp, min = 0;
    for (int i = 0; i < n; i++)
    {
        min = i;
        // 循环查找最小值
        for (int j = i + 1; j < n; j++)
        {
            if (nums[min] > nums[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&nums[min], &nums[i]);
        }
    }
}

int main()
{
    int nums[] = {3, 48, 44, 38, 5, 47, 15, 31, 26, 2, 27, 46, 4, 19, 50, 48, 44};
    int n = sizeof(nums) / sizeof(nums[0]);
    SelectionSort(nums, n);
    printArray(nums, n);
    return 0;
}
