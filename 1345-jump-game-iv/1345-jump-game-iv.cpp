class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), level = 0;
        unordered_map<int, vector<int>>mp;
        
        for(int i=0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n, 0);
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int cur = q.front(); q.pop();
                vector<int>&next = mp[arr[cur]];
                if(cur == n-1) return level;
                next.push_back(cur-1);
                next.push_back(cur+1);
                for(int nxt:next) {
                    if(nxt >= 0 && nxt < n && vis[nxt] == 0) {
                        q.push(nxt);
                        vis[nxt] = 1;
                    }
                }
                next.clear();
            }
            level++;
        }
        return -1;
    }
};