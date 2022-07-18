class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        unordered_set<string>vis;
        if(beginWord == endWord) return 0;
        int depth = 1;
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front();
                q.pop();
                if(cur == endWord) return depth;
                for(int i=0; i<cur.size(); i++) {
                    int ch = cur[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(ch == c) continue;
                        cur[i] = c;
                        if(st.find(cur) != st.end() && vis.find(cur) == vis.end()) {
                            q.push(cur);
                            vis.insert(cur);
                        }
                    }
                    cur[i] = ch;
                }
            }
            depth++;
        }
        return 0;
    }
};