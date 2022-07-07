class Solution {
public:
    bool queryString(string s, int n) {
        vector<bool>seen(n+1, false);
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            int num = 0;
            for(int j=i; j<s.size() && num < n; j++){
                num = (num<<1) + (s[j] - '0');
                if(num >= 1 && num <= n && seen[num] == false) {
                    seen[num] = true;
                }
            }
        }
        for(int i=1; i<=n; i++) {
            if(!seen[i]) return false;
        }
        return true;
    }
};