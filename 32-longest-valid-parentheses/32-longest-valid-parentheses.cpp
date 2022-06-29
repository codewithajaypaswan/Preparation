class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        stack<int>ch, num;
        num.push(-1);
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                num.push(i);
                ch.push(i);
            }
            else if(s[i] == ')' && !ch.empty()) {
                ch.pop(); num.pop();
                ans = max(ans, i - num.top());
            }
            else {
                num.push(i);
            }
        }
        return ans;
    }
};