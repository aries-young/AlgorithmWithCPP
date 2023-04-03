#include <bits/stdc++.h>
using namespace std;

// 输入 n 行，每行 3 个数，第 i 行表示结点 i 的信息，包含三个数 val, left_id, right_id

struct TreeNode {
    int val;
    // int leftId, rightId;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};


// 建树
TreeNode* buildBinaryTree(vector<vector<int>> node_infos, vector<TreeNode>& nodes, int rootId) {
    for (int i = 0; i < node_infos.size(); i++) {
        int val, leftId, rightId;

        val = node_infos[i][0];
        leftId = node_infos[i][1];
        rightId = node_infos[i][2];

        TreeNode* cur = &nodes[i];

        cur->val = val;
        if (leftId != -1) cur->left = &nodes[leftId];
        if (rightId != -1) cur->right = &nodes[rightId];
    }
    TreeNode* root = &nodes[rootId];
    return root;
}

// 计算树高
int Depth (TreeNode* root) {
    int l_depth, r_depth;
    if (root == nullptr) return 0;
    l_depth = Depth(root->left);
    r_depth = Depth(root->right);
    return max(l_depth, r_depth) + 1;
}

int main() {

    // 建树
    int n, rootId;
    n = 3;
    rootId = 0;

    vector<vector<int>> node_infos = {{4, 1, 2}, {3, -1, -1}, {5, -1, -1}};


    vector<TreeNode> nodes(n);
    TreeNode* root = buildBinaryTree(node_infos, nodes, rootId);

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;

}
