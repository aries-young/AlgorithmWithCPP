#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        presum.resize(nums.size() + 1);
        for (int i = 1;i < presum.size(); i++)
            presum[i] = presum[i - 1] + nums[i - 1];
    }
    
    int sumRange(int left, int right) {
        return presum[right + 1] - presum[left];
    }
};

// 调库
vector<int> cal_Presum(vector<int> nums) {
    vector<int> preSum;
    preSum.push_back(0);
    partial_sum(nums.begin(), nums.end(), back_inserter(preSum));
    return preSum;
}
