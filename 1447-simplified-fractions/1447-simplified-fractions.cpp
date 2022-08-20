class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        unordered_set<double>st;
        for(int num = 1; num < n; num++) {
            for(int dem = 2; dem <= n; dem++) {
                if(num >= dem) continue;
                double fraction = (double)num/dem;
                if(st.find(fraction) != st.end()) continue;
                st.insert(fraction);
                string s = to_string(num) + "/" + to_string(dem);
                ans.push_back(s);
            }
        }
        return ans;
    }
};