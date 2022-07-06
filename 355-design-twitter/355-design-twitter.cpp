class Twitter {
public:
    unordered_map<int, set<int>>fo; // followerId, followeeId
    unordered_map<int, vector<pair<int,int>>>tw; // userid, time, tweetId
    int timer = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tw[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:tw[userId]) {
            pq.push(it);
        }
        for(auto f:fo[userId]) {
            for(auto it:tw[f]) {
                pq.push(it);
            }
        }
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            ans.push_back(it.second);
            if(ans.size() == 10) return ans;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */