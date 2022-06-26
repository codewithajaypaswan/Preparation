class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>beg(n+1, 0), end(n+1, 0);
        for(int i=0; i<n; i++) {
            beg[i+1] = beg[i] + cardPoints[i];
        }
        for(int i=n-1; i>=0; i--) {
            end[i] = end[i+1] + cardPoints[i];
        }
        int ans = 0;
        for(int i=0; i<=k; i++) {
            // cout<<beg[i]<<" "<<end[n-k+i]<<endl;
            ans = max(beg[i] + end[n-k+i], ans);
        }
        return ans;
    }
};