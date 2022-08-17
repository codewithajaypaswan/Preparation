class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>st;
        for(string word:words) {
            string str;
            for(char c:word) {
                str += morse[c - 'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};