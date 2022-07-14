class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0, cnt = 0; i<hours.size(); i++) {
            cnt += hours[i] > 8 ? 1 : -1;
            if(cnt > 0) ans = i+1;
            else if(mp.find(cnt - 1) != mp.end()) {
                ans = max(ans, i - mp[cnt - 1]);
            }
            else if(mp.find(cnt) == mp.end()) {
                mp[cnt] = i;
            }
        }
        return ans;
    }
};