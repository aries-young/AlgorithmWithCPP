#include <bits/stdc++.h>
using namespace std;

// 一维前缀和

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


// 二维前缀和
class NumMatrix {
private:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n > 0) {
            int m = matrix[0].size();
            preSum.resize(n + 1, vector<int>(m + 1, 0));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, row2++, col1++, col2++;
        return preSum[row2][col2] - preSum[row1 - 1][col2] - preSum[row2][col1 - 1] + preSum[row1 - 1][col1 - 1];
    }
};