class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        vec.push_back(val);
        int n = vec.size();
        mp[val] = n-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        auto it = mp.find(val);
        // change vector
        vec[it->second] = vec.back();
        vec.pop_back();
        // change map
        mp[vec[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = vec.size();
        return vec[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */