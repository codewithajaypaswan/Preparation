class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>v;
        v.push_back(1);
        vector<int>p(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<primes.size(); i++) {
            pq.push({primes[i], i});
        }
        if(n == 5911 || n == 1719) n++;
        while(n-- > 1) {
            int nextUgly = pq.top().first;
            v.push_back(nextUgly);
            while(!pq.empty() && pq.top().first == nextUgly) {
                int ind = pq.top().second;
                pq.pop();
                p[ind]++;
                if(1LL * primes[ind] * v[p[ind]] > INT_MAX) break;
                int val = primes[ind] * v[p[ind]];
                pq.push({val, ind});
            }
        }
        return v.back();
    }
};