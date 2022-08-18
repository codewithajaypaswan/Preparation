class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x:arr) {
            mp[x]++;
        }
        priority_queue<int>pq;
        for(auto it:mp) {
            pq.push(it.second);
        }
        int n = arr.size(), sum = 0;
        int cnt = 0;
        while(sum < n/2) {
            sum += pq.top(); pq.pop();
            cnt++;
        }
        return cnt;
    }
};