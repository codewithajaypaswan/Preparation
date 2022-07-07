class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>st;
        for(auto c:circles) {
            int x = c[0], y = c[1], r = c[2];
            for(int i=-r; i<=r; i++) {
                for(int j=-r; j<=r; j++) {
                    if(i*i + j*j <= r*r) {
                        st.insert({x + i, y + j});
                    }
                }
            }
        }
        return st.size();
    }
};