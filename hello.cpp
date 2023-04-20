#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

class Difference {
private:
    vector<int> diff;
public:
    Difference(int n) {
        diff = vector<int>(n, 0);
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

int main() {
    int n;
    cin >> n;
    int start = INT_MAX, end = INT_MIN;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        start = min(start, s);
        end = max(end, e);
        
    }

    cout << ans << endl;
}