class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, balance = 0, ans = 0;
        for(int i=0; i<gas.size(); i++) {
            total += gas[i] - cost[i];
            balance += gas[i] - cost[i];
            if(balance < 0) {
                ans = i+1;
                balance = 0;
            }
        }
        return total < 0 ? -1 : ans;
    }
};