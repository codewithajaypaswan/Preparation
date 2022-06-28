class Solution {
public:
    int racecar(int target) {
        queue<pair<int,int>>q; // pos, speed
        q.push({0, 1});
        unordered_set<string>vis;
        string key = to_string(0) + "*" + to_string(1);
        vis.insert(key);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto[pos, speed] = q.front(); q.pop();
                if(pos == target) return level;
                // for A->
                int newPos = pos+speed;
                int newSpeed = speed * 2;
                string key = to_string(newPos) + "*" + to_string(newSpeed);
                if(!vis.count(key) && abs(target - newPos) < target) {
                    vis.insert(key);
                    q.push({newPos, newSpeed});
                }
                // for B->
                newPos = pos;
                newSpeed = speed > 0 ? -1 : 1;
                vis.insert(key);
                key = to_string(newPos) + "*" + to_string(newSpeed);
                if(!vis.count(key) && abs(target - newPos) < target) {
                    vis.insert(key);
                    q.push({newPos, newSpeed});
                }
            }
            level++;;
        }
        return -1;
    }
};