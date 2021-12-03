// 28. 实现strStr()
// 实现 strStr() 函数。
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle
// 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

// 说明：
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C
// 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

// 示例 1：
// 输入：haystack = "hello", needle = "ll"
// 输出：2

// 示例 2：
// 输入：haystack = "aaaaa", needle = "bba"
// 输出：-1

// 示例 3：
// 输入：haystack = "", needle = ""
// 输出：0

// 提示：
// 0 <= haystack.length, needle.length <= 5 * 104
// haystack 和 needle 仅由小写英文字符组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/implement-strstr
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i + m <= n; i++) {
      bool flag = true;
      // 这里的break是跳出里面的这个循环，也就是下一次进来i变成1，j还是从0（也就是从头开始进行匹配），以此类推
      // 就拿测试案例hello举例：haystack从位置0开始和needle逐个比较，一开始h和l不匹配，flag = false，break出去
      // 第二次i+1之后，e和l对比，同上

      // 第三次l和l对比上了，所以if条件就不满足，也就不会把flag设置成false，同时也不会break，所以这个时候j会+1，
      // haystack[i + j]在haystack的指针也会向后移动一位，这个时候第二个l和needle的第二个l也对比上了，于此同时
      // j < m不成立了也就结束了for循环，此时flag为true，就返回了i值2
      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          flag = false;
          break; 
        }
      }
      if (flag) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  string haystack = "hello";
  string needle = "ll";
  Solution s;
  int result = s.strStr(haystack, needle);
  cout << result << endl;
  return 0;
}