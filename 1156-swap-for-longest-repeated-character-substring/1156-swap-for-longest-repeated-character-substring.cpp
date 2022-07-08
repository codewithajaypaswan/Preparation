class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int>left(n), right(n), freq(26, 0);
        left[0] = 1;
        freq[text[0] - 'a']++;
        for(int i=1; i<n; i++) {
            if(text[i] == text[i-1]) {
                left[i] = left[i-1] + 1;
            }
            else {
                left[i] = 1;
            }
            freq[text[i] - 'a']++;
        }
        
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            if(text[i] == text[i+1]) {
                right[i] = right[i+1] + 1;
            }
            else {
                right[i] = 1;
            }
        }
        int ans = max(left[n-1], right[0]);
        for(int i=0; i<n; i++) {
            if(i-1 >= 0 && i+1 < n && text[i-1] == text[i+1] && text[i] != text[i-1]) {
                // cout<<freq[text[i-1] - 'a']<<" "<<left[i-1]<< " "<<right[i+1]<<endl;
                if(freq[text[i-1] - 'a'] == left[i-1] + right[i+1]) {
                    ans = max(ans, left[i-1]+right[i+1]);
                }
                else {
                    ans = max(ans, left[i-1] + right[i+1] + 1);
                }
            }
            else {
                if(freq[text[i] - 'a'] == left[i]) {
                    ans = max(ans, left[i]);
                }
                else {
                    ans = max(ans, left[i] + 1);
                }
            }
        }
        return ans;
    }
};