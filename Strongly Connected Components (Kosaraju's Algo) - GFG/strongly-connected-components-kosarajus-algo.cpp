// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>revAdj[V];
        for(int i=0; i<V; i++) {
            for(auto x:adj[i]) {
                revAdj[x].push_back(i);
            }
        }
        
        // do topological sort
        vector<int>st, vis(V, 0);
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                dfs(adj, i, st, vis);
            }
        }
        int cnt = 0;
        for(int i=0; i<V; i++) vis[i] = 0;
        
        for(int i=st.size()-1; i>=0; i--) {
            int x = st[i];
            if(vis[x]) continue;
            dfs(revAdj, x, st, vis);
            cnt++;
        }
        return cnt;
    }
    
    void dfs(vector<int>adj[], int cur, vector<int>&st, vector<int>&vis) {
        if(vis[cur] == 1) return;
	    vis[cur] =1;
	    for(auto x:adj[cur]) {
	        dfs(adj, x, st, vis);
	    }
	    st.push_back(cur);
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends