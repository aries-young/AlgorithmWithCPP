#include <bits/stdc++.h>
using namespace std;


// 判断出栈序列是否合法
bool outStkIsLegal(const string& input, const string& output) {
    queue<char> q;
    stack<char> stk;

    for (auto ch: input) q.push(ch);

    for (int i = 0; i < (int)output.size(); i++) {
        auto cur = output[i];
        if (!stk.empty() && stk.top() == cur) {
            stk.pop();
        }
        else {
            while (!q.empty() && q.front() != cur) {
                auto tmp = q.front();
                q.pop();
                stk.push(tmp);
            }
            if (q.empty()) return false;
            q.pop();
        }
    }
    return true;
}


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
