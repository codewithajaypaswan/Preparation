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
        int ans = 0, E = V;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int u = it.second, wt = it.first;
            if(vis[u]) continue;
            vis[u] = 1;
            ans += wt;
            E--;
            if(E == 0) return ans;
            for(auto x:adj[u]) {
                int v = x[0], wt_v = x[1];
                if(vis[v] == 0) {
                    pq.push({wt_v, v});
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