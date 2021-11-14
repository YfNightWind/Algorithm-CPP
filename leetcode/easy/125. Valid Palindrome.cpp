// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:
// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 解释："amanaplanacanalpanama" 是回文串

// 示例 2:
// 输入: "race a car"
// 输出: false
// 解释："raceacar" 不是回文串

// 提示：
// 1 <= s.length <= 2 * 105
// 字符串 s 由 ASCII 字符组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-palindrome
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <ctype.h>


using namespace std;

// 使用双指针的做法
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            // 左指针，如果遇到非数字或字母，就往右走
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            // 右指针，如果遇到非数字或字母，就往左走
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                // 因为题中说只考虑字母和数字字符，可以忽略字母的大小写
                // 所以使用tolower，将其全部转换为小写进行比较
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                } else {
                    ++left;
                    --right;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solotion;
    string s = "A man, a plan, a canal: Panama";
    bool result = solotion.isPalindrome(s);
    cout << result; // true
    return 0;
}
