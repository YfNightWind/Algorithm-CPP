// 14. 最长公共前缀

// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1：
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"

// 示例 2：
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。

// 提示：
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] 仅由小写英文字母组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-common-prefix
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string result = "";
    int n = strs.size();
    // 第一次完整遍历的时候i一直都是0，所以在第二个for循环中从头到尾都是在判断每一个项的第一个字符是不是相同的
    // 如果都是相同，那就回到上一级for循环，开始判断每一项的第二个字符是不是也是相等的，所以这就是为什么if中需要写成[j][i]
    for (int i = 0; strs[0][i]; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (strs[j][i] != strs[j + 1][i]) {
          return result;
        }
      }
      // 第二个for循环每完成一次，就将这个值添加到result的后面，以此类推。
      // 因为是公共前缀，所以只要以第一个为准就行所以是[0][i]
      result.push_back(strs[0][i]);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<string> strs = {"flower", "flow", "flight"};
  string ans = s.longestCommonPrefix(strs);

  cout << ans << endl;
}