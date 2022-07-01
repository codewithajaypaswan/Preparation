class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), cmp);
        vector<int>v;
        v.push_back(env[0][1]);
        for(int i=1; i<n; i++) {
            if(v.back() < env[i][1]) {
                v.push_back(env[i][1]);
            }
            else {
                int ind = lower_bound(v.begin(), v.end(), env[i][1]) - v.begin();
                v[ind] = env[i][1];
            }
        }
        return v.size();
    }
};