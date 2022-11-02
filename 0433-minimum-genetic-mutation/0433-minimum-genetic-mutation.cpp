class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st(bank.begin(), bank.end()), visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        int level = 0;
        string gene = "ACGT";
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front(); q.pop();
                if(cur == end) return level;
                for(int i=0; i<cur.size(); i++) {
                    char ch = cur[i];
                    for(char c:gene) {
                        if(cur[i] == c) continue;
                        cur[i] = c;
                        if(visited.find(cur) != visited.end()) continue;
                        visited.insert(cur);
                        if(st.find(cur) != st.end()) q.push(cur);
                    }
                    cur[i] = ch;
                }
            
            }
            level++;
        }
        return -1;
    }
};