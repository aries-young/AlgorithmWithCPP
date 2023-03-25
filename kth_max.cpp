#include <bits/stdc++.h>
using namespace std;

int kth_max(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for(auto k: nums) {
        heap.push(k);
        if (heap.size() > k) heap.pop(); 
    }

    return heap.top();
}



