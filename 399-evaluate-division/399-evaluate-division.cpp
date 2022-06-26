class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& val, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>>mp;
        for(int i=0; i<e.size(); i++) {
            mp[e[i][0]].push_back({e[i][1], val[i]});
            mp[e[i][1]].push_back({e[i][0], 1/val[i]});
        }
        vector<double>ans;
        for(int i=0; i<q.size(); i++) {
            string x = q[i][0], y = q[i][1];
            double res = -1.0, cur = 1.0;
            set<string>vis;
            dfs(mp, res, cur, vis, x, y);
            ans.push_back(res);
        }
        return ans;
    }
    void dfs(map<string, vector<pair<string, double>>>&mp, double &res, double cur, set<string>&vis, string &src, string &dest) {
        if(vis.count(src)) return;
        else if(mp[src].size() == 0) return;
        if(src == dest) {
            res = cur;
            return;
        }
        vis.insert(src);
        for(auto it:mp[src]) {
            dfs(mp, res, cur * it.second, vis, it.first, dest);
        }
    }
};