class Solution {
public:
    vector<int> topological(vector<int>adj[], int k) {
        vector<int>indegree(k+1, 0);
        for(int i=1; i<=k; i++) {
            for(int x:adj[i]) {
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=1; i<=k; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int x:adj[cur]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            } 
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k, vector<int>(k, 0));
        vector<int>graph1[k+1], graph2[k+1];
        for(auto x:rowConditions) {
            graph1[x[0]].push_back(x[1]);
        }
        for(auto x:colConditions) {
            graph2[x[0]].push_back(x[1]);
        }
        vector<vector<int>>res;
        vector<int>arr1 = topological(graph1, k);
        vector<int>arr2 = topological(graph2, k);
        if(arr1.size() != k || arr2.size() != k) return res;
        map<int,int>mp;
        for(int i=0; i<arr1.size(); i++) {
            mp[arr1[i]] = i;
        }
        for(int i=0; i<arr2.size(); i++) {
            ans[mp[arr2[i]]][i] = arr2[i];
        }
        return ans;
    }
};