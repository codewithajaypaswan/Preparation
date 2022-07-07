class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /*
        Consider we have 5 coins A,B,C,D,E

        According to the problem statement
        F(0) = (0A) + (1B) + (2C) + (3D) + (4E)
        F(1) = (4A) + (0B) + (1C) + (2D) + (3E)
        F(2) = (3A) + (4B) + (0C) + (1D) + (2*E)
        
        F(N) = iteration - sum + A[i-1] * len;
        
        */
        int n = nums.size(), iteration = 0, sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            iteration += i * nums[i];
        }
        int ans = iteration;
        for(int i=1; i<n; i++) {
            iteration = iteration - sum + n * nums[i-1];
            ans = max(ans, iteration);
        }
        return ans;
    }
};