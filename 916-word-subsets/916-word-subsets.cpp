class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string>ans;
        vector<int>freqB(26,0);
        for(string b:B) {
            vector<int>temp(26, 0);
            for(char c:b) {
                temp[c - 'a']++;
                freqB[c - 'a'] = max(freqB[c - 'a'], temp[c - 'a']);
            }
        }
        for(string a:A) {
           vector<int>freqA(26,0);
            for(char c:a) freqA[c-'a']++;
            if(subset(freqB,freqA)) ans.push_back(a);
        }
        return ans;
    }
private:
    bool subset(vector<int>freqB, vector<int>freqA) {
        for(int i=0; i<26; i++) {
            if(freqB[i] > freqA[i]) return false;
        }
        return true;
    }
};