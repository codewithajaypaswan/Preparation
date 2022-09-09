class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int n = arr.size(), mx = INT_MIN, ans = 0;
        for(int i=n-1; i>=0; i--) {
            if(arr[i][1] < mx) ans++;
            mx = max(mx, arr[i][1]);
        }
        return ans;
    }
};