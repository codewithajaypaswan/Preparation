class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int p = puzzles.size(), w = words.size();
        unordered_map<int,int>mp;
        for(string w:words) {
            int mask = 0;
            for(char c:w) {
                mask |= 1<<(c - 'a');
            }
            mp[mask]++;
        }
        vector<int>ans(p, 0);
        for(int i=0; i<p; i++) {
            int mask = 0;
            for(char c:puzzles[i]) {
                mask |= 1<<(c - 'a');
            }
            int submask = mask, cnt = 0;
            while(submask >= 1) {
                if(submask&(1<<(puzzles[i][0] - 'a'))) {
                    cnt += mp[submask];
                }
                submask = (submask-1)&mask;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};