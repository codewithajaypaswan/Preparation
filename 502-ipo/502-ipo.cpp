class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mn;
        priority_queue<int>mx;
        int n = profits.size();
        for(int i=0; i<n; i++) {
            mn.push({capital[i], profits[i]});
        }
        while(k--) {
            while(!mn.empty() && mn.top().first <= w) {
                mx.push(mn.top().second);
                mn.pop();
            }
            if(mx.empty()) break;
            w += mx.top();
            mx.pop();
        }
        return w;
    }
};