#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

int g[maxn + 1][maxn + 1];
int val[maxn + 1][maxn + 1];

// Floyd 实现的最小环算法复杂度是 n^3
// 一般题目中都会超时
int minLoopByFloyd(int n) {
    int dis[maxn + 1][maxn + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = val[i][j];
        }
    }
    int ans = INT_MAX;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return ans;
}