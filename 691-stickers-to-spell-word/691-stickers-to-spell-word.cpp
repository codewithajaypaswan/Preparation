class Solution {
public:
    unordered_map<string, int>dp;
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>>mp(n+1, vector<int>(26, 0));
        for(int i=0; i<stickers.size(); i++) {
            for(char c:stickers[i]) {
                mp[i][c - 'a']++;
            }
        }
        return solve(mp, target);
    }
    int solve(vector<vector<int>>&mp, string &target) {
        if(target == "") return 0;
        if(dp.count(target)) return dp[target];
        vector<int>freq(26, 0);
        for(char c:target) freq[c - 'a']++;
        int ans = INT_MAX;
        for(int i=0; i<mp.size(); i++) {
            if(mp[i][target[0] - 'a'] == 0) continue; // no any matching character so continue
            string temp = "";
            // delete all the character which are matching from stickers
            for(int j=0; j<26; j++) {
                if(freq[j] - mp[i][j] > 0) {
                    temp += string(freq[j] - mp[i][j], 'a'+j);
                }
            }
            int ok = solve(mp, temp);
            if(ok != -1) ans = min(ok+1, ans);
        }
        if(ans == INT_MAX) ans = -1;
        return dp[target] = ans;
    }
};