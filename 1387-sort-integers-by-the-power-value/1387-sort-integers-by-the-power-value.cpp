class Solution {
public:
    unordered_map<int,int>mp;
    int solve(int cur) {
        if(cur == 1) return 0;
        if(mp[cur] > 0) return mp[cur];
        if(cur%2 == 1) return mp[cur] = 1 + solve(cur * 3 + 1);
        else return mp[cur] = 1 + solve(cur/2);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>vp;
        for(int i=lo; i<=hi; i++) {
            vp.push_back({solve(i), i});
        }
        sort(vp.begin(), vp.end());
        return vp[k-1].second;
    }
};