class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int>ans;
        unordered_map<int, vector<int>>mp;
        for(auto r:rectangles) {
            mp[r[1]].push_back(r[0]); // {height, {width1, width2, width3}} // here we can apply BS
        }
        for(int i=0; i<=100; i++) {
            // if(mp[i].size() > 0) {
                sort(mp[i].begin(), mp[i].end());
            // }
        }
        for(auto p:points) {
            int x = p[0], y = p[1], cnt = 0;
            for(int i=y; i<=100; i++) {
                if(mp.find(i) == mp.end()) continue;
                cnt += mp[i].size() - binarySearch(mp[i], x);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    int binarySearch(vector<int>&arr, int x) {
        int n = arr.size();
        int low = 0, high = arr.size()-1, ans = arr.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] >= x) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};