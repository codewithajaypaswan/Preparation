class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<char, int>>pq;
        for(auto it:mp) {
            pq.push({it.first, it.second});
        }
        
        string ans;
        
        while(!pq.empty()) {
            // put the max cnt of element
            auto[ch, cnt] = pq.top(); pq.pop();
            int x = min(cnt, repeatLimit);
            ans += string(x, ch);
            if(cnt - x > 0) {
                if(pq.empty()) return ans;
                else {
                    auto[ch2, cnt2] = pq.top(); pq.pop();
                    ans += ch2;
                    pq.push({ch, cnt - x});
                    if(cnt2-1 > 0) pq.push({ch2, cnt2 - 1});
                }
            }
        }
        return ans;
    }
};