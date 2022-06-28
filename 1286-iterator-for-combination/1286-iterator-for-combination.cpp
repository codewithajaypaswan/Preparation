class CombinationIterator {
public:
    vector<string>v;
    int i = 0;
    void solve(string s, int len, string str, int idx) {
        
        if(str.size() == len) {
            v.push_back(str);
            return;
        }
        
        
        if(idx >= s.size()) return;
        str += s[idx];
        
        solve(s, len, str, idx+1);
        str.pop_back();
        solve(s, len, str, idx+1);
    }
    CombinationIterator(string characters, int combinationLength) {
        sort(characters.begin(), characters.end());
        solve(characters, combinationLength, "", 0);
        // sort(v.begin(), v.end());
    }
    
    string next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i != v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */