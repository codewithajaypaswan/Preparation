class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] > B[0];
    }
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);
        int cnt = 0;
        vector<int>parentA(n+1, -1), parentB(n+1, -1);
        for(auto e:edges) {
            if(e[0] == 3) {
                int pu = find(e[1], parentA);
                int pv = find(e[2], parentA);
                
                int pu1 = find(e[1], parentB);
                int pu2 = find(e[2], parentB);

                if(pu != pv) parentA[pu] = pv;
                if(pu1 != pu2) parentB[pu1] = pu2;
                if(pu == pv && pu1 == pu2) cnt++;
            }
            else if(e[0] == 1) {
                int pu = find(e[1], parentA);
                int pv = find(e[2], parentA);

                if(pu == pv) cnt++;
                else parentA[pu] = pv;
            }
            else {
                int pu1 = find(e[1], parentB);
                int pu2 = find(e[2], parentB);
                
                if(pu1 == pu2) cnt++;
                else parentB[pu1] = pu2;
            }
        }
        int cntA = 0, cntB = 0;
        // cout<<cnt<<endl;
        // for(int i=1; i<=n; i++) cout<<parentA[i]<<" ";
        // cout<<endl;
        // for(int i=1; i<=n; i++) cout<<parentB[i]<<" ";
        // cout<<endl;
        for(int i=1; i<=n; i++) {
            if(parentA[i] == -1) cntA++;
            if(parentB[i] == -1) cntB++;
        }
        if(cntA != 1 || cntB != 1) return -1;
        return cnt;
    }
};