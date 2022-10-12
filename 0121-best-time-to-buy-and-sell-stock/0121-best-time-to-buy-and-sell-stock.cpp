class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = INT_MAX;
        for(int i=0; i<prices.size(); i++) {
            buy = min(prices[i], buy);
            ans = max(ans, prices[i] - buy);
        }
        return ans;
    }
};