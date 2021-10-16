#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& nums)
{
    int key, j;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main()
{
    vector<int> nums = {6, 5, 3, 1, 8, 7, 2, 4};
    InsertionSort(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}