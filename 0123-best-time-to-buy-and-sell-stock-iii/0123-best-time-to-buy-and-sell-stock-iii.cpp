class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>left(n), right(n);
        int leftMin = prices[0];
        for(int i=1; i<n; i++) {
            leftMin = min(leftMin, prices[i]);
            left[i] = max(left[i-1], prices[i] - leftMin);
        }
        int rightMax = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            rightMax = max(rightMax, prices[i]);
            right[i] = max(right[i+1], rightMax - prices[i]);
        }
        int ans = left[n-1];
        for(int i=1; i<n; i++) {
            ans = max(ans, left[i-1] + right[i]);
        }
        return ans;
    }
};