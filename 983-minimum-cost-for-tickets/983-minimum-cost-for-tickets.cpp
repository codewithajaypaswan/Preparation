class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        vector<int>dp(31, 0);
        unordered_set<int>st(days.begin(), days.end());
        dp[0] = 0;
        for(int i=days.front(); i<=days.back(); i++) {
            if(st.find(i) == st.end()) dp[i%30] = dp[(i-1)%30];
            else dp[i%30] = min({dp[(i-1)%30] + cost[0], dp[(max(0, i-7))%30] + cost[1], dp[(max(0, i-30))%30] + cost[2]});
        }
        return dp[days.back()%30];
    }
};