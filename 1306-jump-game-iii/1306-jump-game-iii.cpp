class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n = arr.size();
        q.push(start);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(arr[cur] == 0) return true;
            int jump = arr[cur];
            // arr[cur + arr[i]] < 0 , that means the array is already visited so visit the same path we will again get the same set verties
            if(cur + jump < n && arr[cur + jump] >= 0) q.push(cur + jump);
            if(cur - jump >= 0 && arr[cur - jump] >= 0) q.push(cur - jump);
            arr[cur] = -1;
        }
        return false;
    }
};