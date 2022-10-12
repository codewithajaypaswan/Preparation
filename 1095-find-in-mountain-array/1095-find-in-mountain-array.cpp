/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &arr) {
        int ans = 0, n = arr.length();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid+1 < n && arr.get(mid) < arr.get(mid+1)) {
                ans = mid+1;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int low = 0, high = peak;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        low = peak+1, high = mountainArr.length()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};