class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = -1, ans = 0, n = seats.size();
        for(int i=0; i<n; i++) {
            if(seats[i] == 0) continue;
            else if(left == -1) ans = i;
            else ans = max(ans, (i - left)/2);
            left = i;
        }
        ans = max(ans, n - 1 - left);
        return ans;
    }
};