#include <bits/stdc++.h>
using namespace std;

class SegTreeLazyRangeAdd
{
private:
    vector<int> tree, lazy;
    vector<int> *arr;
    int n, root, n4, end;

    void build(int s, int t, int p) {
        // 对 [s, t] 区间建立线段树，当前跟的编号为 p
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void maintain(int cl, int cr, int p) {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && lazy[p]) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] += lazy[p] * (cr - cm);
            lazy[p] = 0;
        }
    }

    void _rangeAdd(int l, int r, int val, int cl, int cr, int p) {
        // [l, r] 为修改区间，val 为被修改元素的变化量
        // [cl, cr] 为当前结点包含的区间
        // p 为当前结点的编号
        if (l <= cl && cr <= r) {
            lazy[p] += val;
            tree[p] += (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr -cl) / 2;
        maintain(cl, cr, p);
        if (l <= m) _rangeAdd(l, r, val, cl, m, p * 2);
        if (r > m) _rangeAdd(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    int _rangeSum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        int sum = 0;
        maintain(cl, cr, p);
        if (l <= m) sum += _rangeSum(l, r, cl, m, p * 2);
        if (r > m) sum += _rangeSum(l, r, m + 1, r, p * 2 + 1);
        return sum;
    }

public:
    SegTreeLazyRangeAdd(vector<int> v) {
        n = v.size();
        n4 = n * 4;
        tree.resize(n4, 0);
        lazy.resize(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    int rangeSum(int l, int r) {return _rangeSum(l, r, 0, end, root); }
    void rangeAdd(int l, int r, int val) { _rangeAdd(l, r, val, 0, end, root); }

    void show(int p, int depth = 0) {
        if (p > n4 || tree[p] == 0) return;
        show(p * 2, depth + 1);
        for (int i = 0; i < depth; i++) putchar('\t');
        printf("%d:%d\n", tree[p], lazy[p]);
        show(p * 2 + 1, depth + 1);
    }
};

int main() {
    vector<int> nums = {10, 11, 12, 13, 14};
    SegTreeLazyRangeAdd seg_tree(nums);
    printf("----> show seg tree ---->\n");
    seg_tree.show(1);
    seg_tree.rangeAdd(2, 4, 5);
    printf("----> show seg tree ---->\n");
    seg_tree.show(1);
    // 注意 seg_tree 中 tree 的 p 是从下标 1 开始的
    // 但是 nums 中的区域 [l, r] 的下标还是从 0 开始
    cout << seg_tree.rangeSum(2, 4) << endl;
    
}
