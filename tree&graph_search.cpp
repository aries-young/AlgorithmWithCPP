#include <bits/stdc++.h>
using namespace std;

// 有一种办法，如果是在牛客这种平台遇到树的问题
// 把树存成图然后按照图的方式进行 BFS 或 DFS 

// Visit 对节点进行访问，具体操作依问题而定
void Visit(int x) { cout << x << endl; }

// 图中的 BFS 即树的层遍历
vector<bool> visited;
void bfs(vector<vector<int>>& graph, int start) {
    queue<int> q;
    int step = 0;

    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto cur = q.front();
            q.pop();
            Visit(cur);
            vector<int> adj = graph[cur];
            for(int j = 0; j < adj.size(); j++) {
                if (adj[i] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
            step += 1;
        }
    }
}

// 双向 BFS 
// 传统的 BFS 框架就是从起点开始向四周扩散，遇到终点时停止
// 而双向 BFS 则是从起点和重点同时开始扩散，当两边有交集的时候停止

/****注意：双向 BFS 只适用于无权图或边权相等的图，对于有全权图不适用****/
/****注意：双向 BFS 从大 O 衡量标准看，时间复杂度都是一样的****/
/****注意：双向队列的实现不再使用 queue，而是使用 set ****/
set<int> q1;
set<int> q2;
set<int> visited_bbfs;
int bidirectionalBFS(vector<vector<int>> graph, int start, int target) {
    q1.insert(start);
    q2.insert(target);
    
    int step = 0;
    
    while (!q1.empty() && !q2.empty()) {
        // 照 BFS 的逻辑，队列（集合）中的元素越多，扩散后新的队列（集合）的元素就越多
        // 在双向 BFS 中，如果我们每次都选择一个较小的集合进行扩散
        // 那么占用的空间增长速度也会慢一些，效率就会高一些
        if (q1.size() > q2.size()) {
            swap(q1, q2);
        }

        set<int> nextLevel;
        for (auto cur: q1) {
            vector<int> adj = graph[cur];
            for (int j = 0 ; j < adj.size(); j++) {
                if (adj[j] == 0) continue;
                
                // 相遇
                if (q2.count(cur)) return step;

                if (!visited_bbfs.count(j)) {
                    nextLevel.insert(j);
                    visited_bbfs.insert(j);
                }
            }
        }
        step++;
        q1 = nextLevel;
    }
    return -1;
}

// 图的 DFS 即树的先序遍历
void dfs(vector<vector<int>> graph, int start) {
    Visit(start);
    visited[start] = true;
    vector<int> adj = graph[start];
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i] == 1 && !visited[i]) dfs(graph, i);
    }
}

// 棋盘的 DFS
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> visited_grid;
void dfsBoard(vector<vector<int>> grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return;

    if (visited_grid[i][j]) return;

    visited_grid[i][j] = true;

    for (auto d: directions) {
        dfsBoard(grid, i + d[0], j + d[1]);
    }
}



