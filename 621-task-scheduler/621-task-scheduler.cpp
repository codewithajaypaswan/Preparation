class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        int mxFreq = 0;
        for(int x:tasks) {
            mp[x]++;
            mxFreq = max(mxFreq, mp[x]);
        }
        int ans = (mxFreq-1) * (n+1);
        for(auto it:mp) {
            if(it.second == mxFreq) ans++;
        }
        return max(ans, (int)tasks.size());
    }
};