class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>>hash(n+1, vector<int>(26, 0));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<26; j++) hash[i][j] = hash[i-1][j];
            hash[i][s[i-1] - 'a']++;
        }
        vector<bool>ans;
        for(auto q:queries) {
            int l = q[0], r = q[1], k = q[2];
            int temp = 0;
            for(int i=0; i<26; i++) {
                temp += (hash[r+1][i] - hash[l][i])%2;
            }
            if(temp/2 <= k) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};