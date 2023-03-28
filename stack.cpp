#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 1;
    // vector 模拟栈
    {
        vector<int> st;
        st.push_back(num);
        int top_element = st.back();
        st.pop_back();
    }

    // 单调栈
    // 某一时刻从栈底到栈顶都是满足递增的关系
    {
        vector<int> nums;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
            while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
                s.pop();
            }
            // ... 依问题而定
            s.push(nums[i]);
        }
    }
}
