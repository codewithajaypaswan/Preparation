class Solution {
public:
    #define ll long long
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(); 
        vector<long long>sum(n+1,0);
        for(int i=0; i<n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        int ans = mergeSort(sum, 0, n, lower, upper);
        return ans;
    }
    int mergeSort(vector<ll>&sum, int low, int high, int lower, int upper) {
        if(low >= high) return 0;
        int mid = low + (high+1- low)/2;
        int count = mergeSort(sum, low, mid-1, lower, upper) + mergeSort(sum, mid, high, lower, upper);
        int startInd = mid, endInd = mid;
        for(int i=low; i<mid; i++) {
            while(startInd <= high && sum[startInd] - sum[i] < lower) {
                startInd++;
            }
            while(endInd <= high && sum[endInd] - sum[i] <= upper) {
                endInd++;
            }
            count += endInd - startInd;
        }
        merge(sum, low, mid, high);
        return count;
    }
    void merge(vector<ll>&sum, int low, int mid, int high) {
        vector<ll>left, right;
        for(int i=low; i<mid; i++) {
            left.push_back(sum[i]);
        }
        for(int i=mid; i<=high; i++) {
            right.push_back(sum[i]);
        }
        int i = 0, j = 0, k = low;
        while(i < left.size() && j < right.size()) {
            if(left[i] <= right[j]) {
                sum[k++] = left[i++];
            }
            else {
                sum[k++] = right[j++];
            }
        }
        while(i < left.size()) {
            sum[k++] = left[i++];
        }
        while(j < right.size()) {
            sum[k++] = right[j++];
        }
    }
};