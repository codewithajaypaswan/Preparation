class Solution {
public:
    bool validPalindrome(string s) {
        int high =s.size()-1, low = 0;
        while(high > low) {
            if(s[high] != s[low]) {
                return isPalindrome(s, low, high-1) || isPalindrome(s, low+1, high);
            }
            high--; low++;
        }
        return true;
    }
    bool isPalindrome(string s, int low, int high) {
        while(low < high) {
            if(s[high] != s[low]) {
                return false;
            }
            high--;
            low++;
        }
        return true;
    }
};