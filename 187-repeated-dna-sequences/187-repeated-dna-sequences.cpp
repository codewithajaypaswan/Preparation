class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
	    // you can also use array or function for this map
        unordered_map<char, int> n2d{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> candidates;
		// this set should be much smaller than the candidates set.  So using string should be ok. 
		// You can also use integer if you want to. 
        unordered_set<string> duplicates;
        int cur = 0;
        for (int i = 0; i < s.length(); i++)
        {
            // only keep at most 9 letters before the current letter
			// or maybe cur &= (1<<19) -1
            cur %= 1<<18;                
            cur = cur * 4 + n2d[s[i]];
            if (i < 9) continue;
            if (candidates.count(cur) > 0)
            {
                duplicates.insert(s.substr(i-9, 10));
            }
            else
            {
                candidates.insert(cur);
            }
        }
        return vector<string>(duplicates.begin(), duplicates.end());
    }
};