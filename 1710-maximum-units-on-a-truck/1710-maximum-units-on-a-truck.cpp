class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for(int i=0; i<boxTypes.size() && truckSize > 0; i++) {
            ans += min(boxTypes[i][0], truckSize) * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        return ans;
    }
};