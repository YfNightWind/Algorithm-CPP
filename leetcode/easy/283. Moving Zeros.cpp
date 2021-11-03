// 283. 移动零

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]

// 说明:
// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。

// 链接：https://leetcode-cn.com/problems/move-zeroes

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    // 使用双指针的方法
    int n = nums.size(), left = 0, right = 0;
    while (right < n) {
        if (nums[right]) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}
// 来源于力扣官方
// 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

// 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

// 注意到以下性质：

// 左指针左边均为非零数；
// 右指针左边直到左指针处均为零。
// 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {
    vector<int> nums = {1, 0, 3, 0, 4, 5, 6};
    moveZeroes(nums);
    for (auto i : nums) {
        cout << i << ' ';
    }
    return 0;
}


// 还有一个方法：
// 但是在网站上会出现overflow，但其实也可以实现
// 使用迭代器，有0就删除，并记录有删了多少次，最后补到数组后面即可
void moveZeroes2(vector<int>& nums) {
    vector<int>:: iterator i;
    int count = 0;
    for (i = nums.begin(); i != nums.end(); ++i) {
        if (*i == 0) {
            i = nums.erase(i);
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        nums.push_back(0);
    }
}