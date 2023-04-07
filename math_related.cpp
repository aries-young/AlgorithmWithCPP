#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

vector<int> isprimes; // i 是否是素数
vector<int> primes; // 素数
// 埃氏筛选求素数 1 ~ n (包括 n) 的素数
// 时间复杂度 O(nloglogn)
int Eratosthenes(int n) {
    int cnt = 0;
    isprimes.resize(n + 1, 1);
    isprimes[0] = isprimes[1] = 0;
    for (int i = 2; i <= n; i++) 
        if(isprimes[i]) {
            cnt++;
            primes.push_back(i);
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) isprimes[j] = 0;
            }
        }
    return cnt;    
}

vector<int> minFators;
// 线性筛求素数和最小质因子 1 ~ n (包括 n) 的素数和最小质因子
// 时间复杂度 O(n)
int linearSieve(int n) {
    minFators.resize(n + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!minFators[i]) {
            cnt++;
            primes.push_back(i);
        }
        for (int j = 0; j < cnt && i * primes[j] <= n; j++) {
            minFators[i * primes[j]] = primes[j];
            // i % pri[j] == 0
            // 换言之，i 之前被 pri[j] 筛过了
            // 由于 pri 里面质数是从小到大的，所以 i乘上其他的质数的结果一定会被
            // pri[j]的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break
            // 掉就好了
            if (i % primes[j] == 0) break;
        }
    }
    return cnt;
}

int main() {
    int n = 15;
    cout << Eratosthenes(n) << endl;
    for (auto i: isprimes) cout << i <<  " ";
    cout << endl;
    for (auto p: primes) cout << p <<  " ";
    cout << endl;
}