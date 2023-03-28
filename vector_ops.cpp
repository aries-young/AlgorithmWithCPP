#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;

    // 求和
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // resize
    vector<int> v;
    v.resize(5, 1);

    // 打印数组
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}