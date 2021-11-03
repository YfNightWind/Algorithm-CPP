// 136. 只出现一次的数字

// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:
// 输入: [2,2,1]
// 输出: 1

// 示例 2:
// 输入: [4,1,2,1,2]
// 输出: 4

// 链接：https://leetcode-cn.com/problems/single-number

#include <iostream>
#include <vector>

using namespace std;

// 使用位运算（异或）来进行解答
// 异或⊕，相同为0，不同为1
int singleNumber(vector<int> &nums) {
    int result = 0;
    for (auto i : nums) {
        // 因为0和任意数据的异或运算都是该数据本身
        // 任何数与自身做异或运算，结果为0
        // 所以将所有数字进行异或，就可以
        // a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
        result ^= i;
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2 ,1 ,2};
    int result = singleNumber(nums);
    cout << "The single number is " << result << endl; // should be 4
    return 0;
}