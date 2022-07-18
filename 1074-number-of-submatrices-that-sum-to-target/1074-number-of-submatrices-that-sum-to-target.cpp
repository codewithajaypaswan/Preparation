class Solution {
public:
    int result = 0, target;
    void get_sum(vector<int>&row) {
        unordered_map<int,int>mp;
        int sum = 0;
        for(int x:row) {
            sum += x;
            if(sum == target) result++;
            if(mp.count(sum-target))
                result += mp[sum-target];
            mp[sum]++;
        }
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        this->target = target;
        for(int i=0; i<n; i++) {
            vector<int>row(m);
            for(int j=i; j<n; j++) {
                for(int x=0; x<m; x++) 
                    row[x] += matrix[j][x];
                get_sum(row);
            }
        }
        return result;
    }
};