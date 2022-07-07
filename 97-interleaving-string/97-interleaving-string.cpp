class Solution {
public:
    unordered_map<string,bool>mp;
    bool check(string s1, string s2, string s3, int l1, int l2, int l3, int i1, int i2, int i3) {
        // base condition
        if(l3 == i3) {
            return (l2==i2 && l1==i1) ? true : false;
        }
        string key = to_string(i1) + "*" + to_string(i2) + "*" + to_string(i3);
        if(mp.find(key) != mp.end()) return mp[key];
        // case 1:
        if(l1 == i1){
            return mp[key] = s2[i2] == s3[i3] ? check(s1,s2,s3,l1,l2,l3,i1,i2+1,i3+1) : false;
        }
        // case 2:
        if(l2 == i2) {
            return mp[key] = s1[i1] == s3[i3] ? check(s1,s2,s3,l1,l2,l3,i1+1,i2,i3+1) : false;
        }
        // case 3:
        bool check1 = false, check2 = false;
        if(s1[i1] == s3[i3])
            check1 = check(s1,s2,s3,l1,l2,l3,i1+1,i2,i3+1);
        if(s2[i2] == s3[i3])
            check2 = check(s1,s2,s3,l1,l2,l3,i1,i2+1,i3+1);
        return mp[key] = check1 || check2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1 + l2 != l3) return false;
        return check(s1,s2,s3,l1,l2,l3,0,0,0);
    }
};