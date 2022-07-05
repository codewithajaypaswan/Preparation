class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        long double sum = 0;
        for(int x:nums) {
            pq.push(x);
            sum += x;
        }
        double target = sum/2, ops = 0;
        while(!pq.empty()) {
            double x = pq.top(); pq.pop();
            sum -= x;
            sum += x/2;
            ops++;
            if(sum <= target) return ops;
            if(x/2) pq.push(x/2);
        }
        return -1;
    }
};