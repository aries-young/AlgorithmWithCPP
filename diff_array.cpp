// 查分数组

#include <bits/stdc++.h>
using namespace std;

class Differece {
private:
    vector<int> diff;
public:
    Differece(vector<int>& nums) {
        diff.resize(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) diff[j + 1] -= val;
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};