class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        unordered_set<double>st;
        for(int dem = 2; dem <= n; dem++) {
            for(int num = 1; num < dem; num++) {
                if(__gcd(num, dem) != 1) continue;
                string s = to_string(num) + "/" + to_string(dem);
                ans.push_back(s);
            }
        }
        return ans;
    }
};