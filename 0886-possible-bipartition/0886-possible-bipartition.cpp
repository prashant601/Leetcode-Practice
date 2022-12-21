class Solution {
public:
    //approaches: bipartite , disjoint set union
    bool bpt(int node, vector<int> adj[], vector<int>&col){
        if(col[node]==-1) col[node]=1;
        for(auto it: adj[node]){
            if(col[it]==-1){
                col[it]=1-col[node];
                if(bpt(it, adj, col)==false) return false;
            }
            else if(col[it]==col[node]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> col(n+1,-1);
        vector<int> adj[n+1];
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(bpt(i,adj,col)==false) return false;
            }
        }
        return true;
    }
};