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
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        for(int i=0; i<V; i++) {
            for(auto u:adj[i]) {
                int v = u[0], wt = u[1];
                pq.push({wt, {i, v}});
            }
        }
        int E = V-1;
        vector<int>parent(V, -1);
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int wt = it.first, u = it.second.first, v = it.second.second;
            int parentU = find(u, parent);
            int parentV = find(v, parent);
            if(parentU == parentV) continue;
            parent[parentU] = parentV;
            ans += wt;
            E--;
            if(E == 0) return ans;
        }
        return ans;
    }
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
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