class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size(), ans = 0;
        for(int i=0; i<n; i++) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for(int i=0; i<n; i++) {
            if(capacity[i] == 0) ans++;
            else if(capacity[i] <= additionalRocks) {
                ans++;
                additionalRocks -= capacity[i];
            }
            else break;
        }
        return ans;
    }
};