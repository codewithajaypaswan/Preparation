class Solution {
public:
    int cntFreq(string s) {
        vector<int>freq(26, 0);
        for(char c:s) {
            freq[c - 'a']++;
        }
        int res = 0;
        for(int i=0; i<26; i++) {
            if(freq[i]) {
                res = freq[i];
                break;
            }
        }
        return res;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size(), m = words.size();
        vector<int>ans, freq(12, 0);
        for(int i=0; i<m; i++) {
            int f = cntFreq(words[i]);
            freq[f]++;
        }
        for(int i=10; i>=0; i--) {
            freq[i] += freq[i+1];
        }
        for(auto q:queries) {
            int f = cntFreq(q);
            ans.push_back(freq[f+1]);
        }
        return ans;
    }
};