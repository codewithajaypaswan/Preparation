class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
        for(int i=0; i<m; i++) {
            pq.push({grid[0][i], 0, i});
        }
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int x = it[1], y = it[2], cost = it[0];
            if(x == n-1) return cost;
            for(int curY = 0; curY < m; curY++) {
                int newCost = cost + moveCost[grid[x][y]][curY] + grid[x+1][curY];
                if(newCost < visited[x+1][curY]) {
                    visited[x+1][curY] = newCost;
                    pq.push({newCost, x+1, curY});
                }
            }
        }
        return -1;
    }
};