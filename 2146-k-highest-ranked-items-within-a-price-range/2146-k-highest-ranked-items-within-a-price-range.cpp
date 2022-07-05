class Solution {
public:
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        vector<vector<int>>ans;
        queue<pair<int,int>>q;
        int n = grid.size(), m = grid[0].size();
        q.push({start[0], start[1]});
        if(grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) ans.push_back({start});
        grid[start[0]][start[1]] = 0;
        while(ans.size() < k && !q.empty()) {
            set<pair<int, pair<int,int>>>st;
            int sz = q.size();
            while(sz--) {
                
                auto[x,y] = q.front(); q.pop();
                
                for(int i=0; i<4; i++) {
                    
                    int curX = dx[i] + x;
                    int curY = dy[i] + y;
                    if(curX < 0 || curX >= n || curY < 0 || curY >= m || grid[curX][curY] == 0) continue;
                    if(grid[curX][curY] >= pricing[0] && grid[curX][curY] <= pricing[1]) {
                        st.insert({grid[curX][curY], {curX, curY}});
                    }
                    
                    grid[curX][curY] = 0;
                    q.push({curX, curY});
                }
            }
            for(auto it:st) {
                ans.push_back({it.second.first, it.second.second});
                if(ans.size() == k) return ans;
            }
        }
        return ans;
        // return {{}};
    }
};