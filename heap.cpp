#include <bits/stdc++.h>
using namespace std;

//升序队列，小顶堆
priority_queue <int, vector<int>, greater<int>> min_heap;
//降序队列，大顶堆
priority_queue <int, vector<int>, less<int>> max_heap;


int kth_max(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for(auto k: nums) {
        heap.push(k);
        if (heap.size() > k) heap.pop(); 
    }

    return heap.top();
}



