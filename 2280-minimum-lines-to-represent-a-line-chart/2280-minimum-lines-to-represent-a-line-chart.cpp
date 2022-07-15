class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        if(n == 1) return 0;
        int cnt = 1;
        for(int i=2; i<n; i++) {
            int x3 = s[i][0], x2 = s[i-1][0], x1 = s[i-2][0];
            int y3 = s[i][1], y2 = s[i-1][1], y1 = s[i-2][1];
            // (y2 - y1)/(x2-x1) = (y3 - y1)/(x3-x1)
            if(1LL * (y2-y1) * (x3-x1) != 1LL * (y3-y1) * (x2-x1)) cnt++;
        }
        return cnt;
    }
};