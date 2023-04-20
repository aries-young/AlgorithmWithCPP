#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

class Difference {
private:
    int n;
    vector<int> diff;
public:
    Difference(int _n) {
        n = _n;
        diff = vector<int>(n, 0);
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < n) diff[j + 1] -= val;
    }
    
    int result(int start, int end) {
        int pre = 0, ans = 0;
        for (int i = 0; i <= end; i++) {
            pre = pre + diff[i];
            if (start <= i) {
                if (pre == 0) ans += 1;
                if (pre == 1) ans += 3;
                if (pre >= 2) ans += 4;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Difference diff(MAXN);
    int start = INT_MAX, end = INT_MIN;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        start = min(start, s);
        end = max(end, e);
        diff.increment(s, e, 1);
    }
    int ans  = diff.result(start, end);
    cout << ans << endl;
}