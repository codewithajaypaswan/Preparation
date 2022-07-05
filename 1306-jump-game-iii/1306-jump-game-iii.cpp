class Solution {
public:
    bool solve(vector<int>&arr, int cur) {
        if(cur < 0 || cur >= arr.size() || arr[cur] < 0) return false;
        if(arr[cur] == 0) return true;
        int jump = arr[cur];
        arr[cur] *= -1;
        return solve(arr, cur+jump) || solve(arr, cur - jump);
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr, start);
    }
};