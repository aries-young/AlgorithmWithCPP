#include <bits/stdc++.h>
using namespace std;

void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (auto c: t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新出操作
        // ...

		// debug
		printf("window: [%d, %d)\n", left, right);

        // 判断左窗口是否要收缩
        while (valid == need.size() /*window needs shrink*/) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新 
            // ... 和上面的更新操作一般是堆成的
        }
    }
}