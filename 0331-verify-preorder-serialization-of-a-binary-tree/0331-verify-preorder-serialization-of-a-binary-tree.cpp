class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        preorder += ',';
        int cap = 1, n = preorder.size();
        for(int i=0; i<n; i++) {
            if(preorder[i] != ',') continue;
            cap--;
            if(cap < 0) return false;
            if(preorder[i-1] != '#') cap += 2;
        }
        return cap == 0;
    }
};