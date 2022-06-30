// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int ans = 0;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, 0});
        vector<int>vis(V, 0);
        int E = V-1;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int wt = it.first, v = it.second;
            if(vis[v]) continue;
            vis[v] = 1;
            ans += wt;
            if(E == 0) return ans;
            E--;
            for(auto x:adj[v]) {
                int nextWt = x[1],  nextV = x[0];
                if(!vis[nextV]) {
                    pq.push({nextWt,nextV});
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends