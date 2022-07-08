class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int,int>mp;
        for(int i=0; i<rs.size(); i++) {
            mp[rs[i][0]] += (1<<rs[i][1]);
        }
        int mask1 = ((1<<4) + (1<<5) + (1<<6) + (1<<7));
        int mask2 = ((1<<2) + (1<<3) + (1<<4) + (1<<5));
        int mask3 = ((1<<6) + (1<<7) + (1<<8) + (1<<9));
        // cout<<mask1<<" "<<mask2<<" "<<mask3<<endl;
        int ans = 0;
        for(auto it:mp) {
            int x = it.second;
            int cnt = 0;
            if((x & mask2) == 0) cnt++;
            if((x & mask3) == 0) cnt++;
            if(cnt == 0 && (x&mask1) == 0) cnt = 1;
            ans += cnt;
        }
        // cout<<ans<<endl;
        return ans + 2 * (n - mp.size());
    }
};