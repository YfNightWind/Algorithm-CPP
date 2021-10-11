// 66. 加一

// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1：
// 输入：digits = [1,2,3]
// 输出：[1,2,4]
// 解释：输入数组表示数字 123。

// 示例 2：
// 输入：digits = [4,3,2,1]
// 输出：[4,3,2,2]
// 解释：输入数组表示数字 4321。

// 示例 3：
// 输入：digits = [0]
// 输出：[1]

// 提示：
// 1 <= digits.length <= 100
// 0 <= digits[i] <= 9

// 链接：https://leetcode-cn.com/problems/plus-one

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if(digits[i] != 9) {
            digits[i]++; // 如果是示例3的话，+1后就输出 为1
            return digits;
        }
        // 最后一位是9，设置为0，回到一开始继续加1.
        digits[i] = 0;
    }
    // 跳出for说明全是9，建立一个新的数组，设定第一个为1，之后添加元数组长度的0即可
    vector<int> result = {1};
    for (int i = 0; i < digits.size(); i++) {
        result.push_back(0);
    }
    return result;
}
int main() {
    vector<int> nums = {1, 9, 9};
    for (auto i : plusOne(nums)) {
        cout << i;
    }
    return 0;
}