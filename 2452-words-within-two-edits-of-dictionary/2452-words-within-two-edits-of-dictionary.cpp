class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(string s:queries) {
            int cnt;
            for(string dic:dictionary) {
                cnt = 0;
                for(int i=0; i<dic.size(); i++) {
                    if(dic[i] != s[i]) cnt++;
                    if(cnt > 2) break;
                }
                if(cnt <= 2) break; 
            }
            if(cnt <= 2) ans.push_back(s);
        }
        return ans;
    }
};