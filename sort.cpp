#include <bits/stdc++.h>
using namespace std;

// <algorithm> std::sort 自定义 comp
// bool comp (int i, int j) { return i < j}
// comp return true:  第一个参数小于第二个参数，
//                    sort 排序时第一个参数排在第二参数之前
// comp return false: 第一个参数大于第二个参数，
//                    sort 排序时第一个参数排在第二个参数之后

// border用来记录上一次最后交换的那个位置
// 下一轮交换只需要进行到这个位置即可
void bubble_sort(vector<int>& nums) {
    int n = nums.size();
    int end = n - 1;
    for (; end > 0; end--) {
        int border = 0;
        for (int i = 1; i <= end; i++) {
            if (nums[i - 1] > nums[i]) {
                swap(nums[i - 1], nums[i]);
                border = i;
            }
        }
        end = border;
    }
}

int main() {
    vector<int> nums = {2, 4, 6, 3, 8, 1, 9};
    bubble_sort(nums);
    for (auto i: nums) cout << i << " ";
    cout << endl;
}