#include <bits/stdc++.h>
using namespace std;

int josephus(int n) {
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    int i = 1;
    while(q.size() > 1) {
        if (true/*i 满足条件不出列*/) q.push(q.front());
        q.pop();
        i++;
    }
    return q.front();
}