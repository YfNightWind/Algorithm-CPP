// 350. 两个数组的交集

// 给定两个数组，编写一个函数来计算它们的交集。

// 示例 1：
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2,2]

// 示例 2:
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[4,9]

// 说明：
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
// 我们可以不考虑输出结果的顺序。

// 链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    // 因为求的是数组的交集，所以先进行排序，可以更好进行对比
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    // 使用双指针的方法
    // 两个数组都是从第一个开始对比
    int p1 = 0;
    int p2 = 0;
    while (p1 < nums1.size() && p2 < nums2.size()) {
        // 如果数组1的小于数组2，数组1的指针就往后移动
        if (nums1[p1] < nums2[p2]) {
            p1++;
        }
        // 同理 数组2的指针向右移动
        else if (nums1[p1] > nums2[p2]) {
            p2++;
        }
        // 如果想等，就符合题意，那么就存入我们要输出的数组
        else {
            result.push_back(nums1[p1]);
            p1++;
            p2++;
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    for (int i = 0; i < intersect(nums1, nums2).size(); i ++) {
        cout << intersect(nums1, nums2)[i] << "," << endl;
    }
    return 0;
}