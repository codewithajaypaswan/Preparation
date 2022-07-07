class Solution {
  public:
    string customSortString(string order, string str) 
    {
        unordered_map<int,int>mp;
        for(char c:str) {
            mp[c]++;
        }
        string ans = "";
        for(char c:order) {
            ans += string(mp[c], c);
            mp[c] = 0;
        }
        for(auto it:mp) {
            ans += string(it.second, it.first);
        }
        return ans;
    }
};