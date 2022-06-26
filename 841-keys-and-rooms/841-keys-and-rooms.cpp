class Solution {
public:
    unordered_set<int>st;
    void dfs(vector<vector<int>>&rooms, int cur) {
        if(st.find(cur) != st.end()) return;
        st.insert(cur);
        for(int x:rooms[cur]) {
            dfs(rooms, x);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        return st.size() == rooms.size();
    }
};