class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int leftInd = -1, rightInd = -1, mxDigit = -1, mxInd = -1;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] > mxDigit) {
                mxDigit = s[i];
                mxInd = i;
            }
            else if(s[i] < mxDigit) {
                rightInd = mxInd;
                leftInd = i;
            }
        }
        if(leftInd == -1) return num;
        swap(s[rightInd], s[leftInd]);
        return stoi(s);
    }
};