class Solution {
public:
    double find(vector<int>&p) {
        double dist = (double) sqrt(p[0] * p[0] + p[1]*p[1]);
        return dist;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>>pq;
        for(auto p:points) {
            pq.push({find(p), {p[0], p[1]}});
        }
        while(pq.size() > k) pq.pop();
        vector<vector<int>>ans;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};