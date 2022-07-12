class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        vector<int>time(n, -1);
        q.push(0);
        time[0] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(auto child:adj[cur]) {
                if(time[child] == -1) {
                    time[child] = time[cur] + 1;
                    q.push(child);
                }
            }
        }
        
        // now calculate the answer
        int ans = 0;
        for(int i=1; i<n; i++) {
            // (totalTime * 2 - 1)/patience[i] 
            int extra = (time[i] * 2 - 1)/patience[i];
            int lastMessage = extra * patience[i];
            int lastTime = 2*time[i] + lastMessage;
            ans = max(ans, lastTime);
        }
        return ans+1;
        
    }
};