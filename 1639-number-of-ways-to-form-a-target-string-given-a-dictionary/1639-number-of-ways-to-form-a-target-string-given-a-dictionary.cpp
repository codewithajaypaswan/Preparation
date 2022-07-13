class Solution {
public:
    vector<vector<long long>>freq, dp;
    string target;
    int _n;
    int mod = 1e9+7;
    int solve(int w, int t) {
        if(t >= target.size()) return 1;
        if(w >= _n) return 0;
        if(dp[w][t] != -1) return dp[w][t];
        int cur = target[t] - 'a';
        return dp[w][t] = (1LL * solve(w+1, t) + (freq[w][cur] * solve(w+1, t+1))%mod)%mod;
    }
    int numWays(vector<string>& words, string _target) {
        target = _target;
        int n = words[0].size(), m = words.size();
        _n = n;
        freq.resize(n+1, vector<long long>(26, 0));
        dp.resize(n+1, vector<long long>(target.size()+1, -1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                freq[j][words[i][j] - 'a']++;
            }
        }
        return solve(0, 0);
    }
};