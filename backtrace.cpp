// 回溯

#include <bits/stdc++.h>
using namespace std;

// result = []

// def backtrack(路径, 选择列表):
// 	if 满足结束条件:
// 		result.add(路径)
// 		return
// 	for 选择 in 选择列表:
// 		做选择
// 		backtrack(路径，选择列表)
// 		撤销选择

// 以排列组合问题说明回溯框架的使用

// 组合
vector<int> track;
void combine(vector<int> nums, int start) {
    for (int i = start; i < nums.size(); i++) {
        // 如果元素有重复，每个元素最多被用到一次
        // nums = [1,2,2] [[],[1],[1,2],[1,2,2],[2],[2,2]]
        // if (i > start && nums[i] == nums[i - 1]) continue;

        // 做选择
        track.push_back(nums[i]);
        // 注意参数
        combine(nums, i + 1);

        // 如果一个元素可以被使用若干次
        // combine(nums, i);

        // 撤销选择
        track.pop_back();
    }
}

// 排列
vector<bool> used; // 如果一个元素可以被使用若干次，就不需要记录 used
void permute(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        // 剪枝
        if (used[i]) continue;

        // 如果元素有重复，每个元素最多被用到一次
        // if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        // 做选择
        used[i] = true;
        track.push_back(nums[i]);
        permute(nums);

        // 取消选择
        track.pop_back();
        used[i] = false;
    }
}

// next_permute 实现全排列
vector<vector<int>> permuteSTL(vector<int>& nums) {
    vector<vector<int>> res;
    do {
        res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
}