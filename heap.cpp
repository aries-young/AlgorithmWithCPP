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

// <algorithm> nth_element 
// 从某个序列中找到第 n 小的元素 K，并将 K 移动到序列中第 n 的位置处
// 经过处理后所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大
//排序规则采用默认的升序排序
// void nth_element (RandomAccessIterator first,
//                   RandomAccessIterator nth,
//                   RandomAccessIterator last);
//排序规则为自定义的 comp 排序规则
// void nth_element (RandomAccessIterator first,
//                   RandomAccessIterator nth,
//                   RandomAccessIterator last,
//                   Compare comp);


int main() {
    vector<int> nums{3, 1, 2, 5, 4};
    nth_element(nums.begin(), nums.begin() + 2, nums.end());
    for (auto i: nums)
        cout << i << " ";
    cout << endl;
}

