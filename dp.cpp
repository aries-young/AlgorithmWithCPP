// DP 问题

#include <bits/stdc++.h>
using namespace std;

// 背包问题

/*
**********************
* 股票买卖
**********************
*/ 

// 状态 
// dp[i][k][0] 第 i 天，最多允许交易 k 次，手上没有股票的最大利润
// dp[i][k][1] 第 i 天，最多允许交易 k 次，手上持有股票的最大利润
// 转移方程
// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
//               max(今天选择 rest,  今天选择 sell            )
// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
//               max(今天选择 rest,  今天选择 buy             )
// base case
// dp[...][0][0] = 0
// dp[...][0][1] = -infinity (INT_MIN)

// 对于 k = 1 的情况
// dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
// dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
//             = max(dp[i-1][1][1], -prices[i])
// 由于 k 都是 1，不会改变，即 k 对状态转移已经没有影响了
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], -prices[i])
// 空间优化
// dp_i0 = max(dp_i0, dp_i1 + prices[i])
// dp_i1 = max(dp_i1, -prices[i])

int maxProfit_k_1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        if (i - 1 == -1)
        {
            dp[i][0]= 0 ;
            dp[i][1]=-prices[i];
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
}

// 对于 k = +infinity 的情况，同样 k 不影响状态转移
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
// 空间优化
// tmp = dp_i0
// dp_i0 = max(dp_i0, dp_i1 + prices[i])
// dp_i1 = max(dp_i1, tmp - prices[i])

// 冷冻期
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
// 空间优化
// tmp = dp_i0
// dp_i0 = max(dp_i0, dp_i1 + prices[i])
// dp_i1 = max(dp_i1, dp_pre0 - prices[i])
// dp_pre0 = dp_i0

// 手续费
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
// 空间优化
// dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
// dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
// dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
// dp[i][1][1] = max(dp[i-1][1][1], -prices[i])
// dp_i20 = max(dp_i20, dp_i21 + price);
// dp_i21 = max(dp_i21, dp_i10 - price);
// dp_i10 = max(dp_i10, dp_i11 + price);
// dp_i11 = max(dp_i11, -price);

// 对于 k = 2
// dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
// dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);

// 打家劫舍
// 棋盘路径
// 字符串
