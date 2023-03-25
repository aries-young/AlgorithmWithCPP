#include <bits/stdc++.h>
using namespace std;

// 取 x 在二进制表示下最低位的 1 以及后面的 0 构成的数值
int lowbit(int x) {return x & (-x); };

// 判断 x 在二进制表示下是否有连续的 1
// 1010 lowbit: 10 1010 & 0100 = 0000
// 1110 lowbit: 10 1110 & 0100 = 0100
int x = 1;
int isFormedByContinuousOne = x & (lowbit(x) << 1);

// 判断 x 是不是 2 的幂次
int isPowerofTwo = x & (x - 1);
