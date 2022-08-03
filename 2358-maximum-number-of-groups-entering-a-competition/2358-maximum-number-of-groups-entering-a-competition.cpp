class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int ans = 0;
        long n = grades.size(), curSum = 0, curCount = 0;
        long prevCount = 0, prevSum = 0;
        for(int i=0; i<n; i++) {
            curSum += grades[i];
            curCount++;
            if(curSum > prevSum && curCount > prevCount) {
                ans++;
                prevSum = curSum;
                prevCount = curCount;
                curSum = curCount = 0;
            }
        }
        return ans;
    }
};