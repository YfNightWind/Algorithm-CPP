// 242. 有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true

// 示例 2:
// 输入: s = "rat", t = "car"
// 输出: false

// 提示:
// 1 <= s.length, t.length <= 5 * 104
// s 和 t 仅包含小写字母

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-anagram
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  // 使用HashMap，先建立一个长度为26的哈希表，先对s进行遍历，并将它每一个值给定一个下标，并且赋值为0
  // 之后再对t遍历的时候，直接进行减，如果小于0了，就说明不是异位词
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    vector<int> hash(26, 0);
    for (auto ch : s) {
      hash[ch - 'a']++;
    }
    for (auto ch : t) {
      hash[ch - 'a']--;
      if (hash[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }

  // 最简易的办法，但是和语言息息相关，直接排序，如果s和t长度不同，必然不是异位词
  bool isAnagramInEasyWay(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
  }
};
int main() {
  string s = "anagram";
  string t = "nagaram";
  Solution solution;
  bool res = solution.isAnagram(s, t);
  bool eRes = solution.isAnagramInEasyWay(s, t);
  cout << res << endl;
  cout << eRes;  // 1 means true;
  return 0;
}