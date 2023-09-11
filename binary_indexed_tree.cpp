#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int a[MAXN], op[MAXN], x[MAXN], y[MAXN];
int n;

int lowbit(int x) {
    return x & (-x);
}

int sum(int x) {
    int s = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        s += a[i];
    }
    return s;
}

int sumRange(int left, int right) {
    if (left > right) return 0;
    return sum(right) - sum(left - 1);
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        a[i] += v;
    }
}

int main()
{

    return 0;
}