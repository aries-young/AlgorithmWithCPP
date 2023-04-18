#include <bits/stdc++.h>
using namespace std;

bool cmp(int num) { return num % 2; }

int main() {
    vector<int> nums;

    // 求和
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // resize
    vector<int> v;
    v.resize(5, 1);

    // 打印数组
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    // vector to set
    set<int> st(nums.begin(), nums.end());
    vector<int> vec;
    vec.assign(st.begin(), st.end());


    // vector to string
    string s = "hello world";
    vector<char> char_vec;
    char_vec.assign(s.begin(), s.end());
    s.assign(char_vec.begin(), char_vec.end());

    // vector count
    // count(vec.begin(), vec.end(), value)
    int cnt = count(nums.begin(), nums.end(), 1);
    // count_if
    int cnt = count_if(vec.begin(), vec.end(), cmp);
}