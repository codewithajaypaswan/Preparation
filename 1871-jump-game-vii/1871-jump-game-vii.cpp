class Solution {
public:
    bool canReach(string s, int a, int b) {
        queue<int>q;
        q.push(0);
        int n = s.size(), mx = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(cur == n-1) return true;
            for(int i=max(mx+1, cur + a); i<=min(n-1, cur + b); i++) {
                if(s[i] == '0') q.push(i);
            }
            mx = cur+b;
        }
        return false;
    }
};