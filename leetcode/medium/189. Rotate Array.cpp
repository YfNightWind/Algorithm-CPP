//
//  189. Rotate Array.cpp
//  Algorithm
//
//  Created by Alex Lin on 2021/9/22.
//

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: nums = [1,2,3,4,5,6,7], k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
//示例 2:
//
//输入：nums = [-1,-100,3,99], k = 2
//输出：[3,99,-1,-100]
//解释:
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100]
//
//链接：https://leetcode-cn.com/problems/rotate-array

//请使用g++ -std=c++11 <filename>进行编译

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k);

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ",";
    }
    return 0;
}


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    // Step1:划分成[1,2,3,4], [5,6,7]
    // Step2:分别reverse，[4,3,2,1], [7,6,5]
    // Step3:合并reverse，[5,6,7,1,2,3,4]
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}
