// 344. 反转字符串
// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s
// 的形式给出。 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用
// O(1) 的额外空间解决这一问题。

// 示例 1：
// 输入：s = ["h","e","l","l","o"]
// 输出：["o","l","l","e","h"]

// 示例 2：
// 输入：s = ["H","a","n","n","a","h"]
// 输出：["h","a","n","n","a","H"]
//  

// 提示：
// 1 <= s.length <= 105
// s[i] 都是 ASCII 码表中的可打印字符

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>

using namespace std;

// 使用双指针，一个在头一个在尾，对称交换
class Solution {
 public:
  void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
  }
  void reverseString(vector<char> &s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};

int main() {
  vector<char> s = {'a', 'b', 'c', 'd'};
  Solution solution;
  solution.reverseString(s);
  for (auto i : s) {
    cout << i;
  }
  return 0;
}