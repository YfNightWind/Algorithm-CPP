// 217. 存在重复元素

// 给定一个整数数组，判断是否存在重复元素。
// 如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

// 示例 1:
// 输入: [1,2,3,1]
// 输出: true

// 示例 2:
// 输入: [1,2,3,4]
// 输出: false

// 示例 3:
// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true

// 链接：https://leetcode-cn.com/problems/contains-duplicate

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    // 用sort函数排序 之后最后对比即可得知，原先想使用选择排序，然后发现超时了
    // 同理两个for循环的蠢办法也不行，会在第19/20的案例超时
    sort(nums.begin(), nums.end());
    int temp = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            temp++;
        }
    }
    if (temp > 1) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool ans = containsDuplicate(nums);
    cout << "The Result is " << ans << endl; // should be 1 and it means true
    return 0;
}