class Solution {
public:
    static bool cmp(pair<int, string>&A, pair<int,string>&B) {
        return A.first == B.first ? A.second < B.second : A.first > B.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string s:words) {
            mp[s]++;
        }
        vector<pair<int, string>>vp;
        for(auto it:mp) {
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end(), cmp);
        vector<string>ans;
        for(int i=0; i<k; i++) {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};