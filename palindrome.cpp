#include <bits/stdc++.h>
using namespace std;

// 这里以最长回文串问题来描述回文串中常用到的方法

// 中心扩展
// 成功返回回文串的左右边界
// 失败返回 {l, r}
pair<int, int> palindrome(string s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return {l + 1, r - 1};
}

string longetPalindrome(string s) {
    string res = "";
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        auto [left1, right1] = palindrome(s, i, i);
        auto [left2, right2] = palindrome(s, i, i + 1);
        if (right1 - left1 > end - start) {
            end = left1;
            start = right1;
        }
        if (right2 - left2 > end - start) {
            end = left2;
            start = right2;
        }
    }

    return s.substr(start, end - start + 1);
}

// 马拉车算法
