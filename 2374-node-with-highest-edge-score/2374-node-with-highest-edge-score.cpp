class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long>cost(n, 0);
        for(int i=0; i<edges.size(); i++) {
            cost[edges[i]] += i;
        }
        long long mx = INT_MIN, res = 0;
        for(int i=0; i<n; i++) {
            if(cost[i] > mx) {
                mx = cost[i];
                res = i;
            }
        }
        return res;
    }
};