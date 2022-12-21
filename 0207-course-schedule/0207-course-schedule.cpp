class Solution {
public:
    bool isCycle(int node, vector<int> adj[], vector<int> &vis, vector<int>&dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        // cout<<node<<" ";
        for(auto i: adj[node]){
            if(vis[i]==0){
                if(isCycle(i,adj, vis, dfsVis)) return true;
            }
            else if(dfsVis[i]==1) return true;
        }
               dfsVis[node]=0;
               return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto i: pre){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0), dfsVis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(isCycle(i, adj, vis, dfsVis)) return false;
            }
        }
        
        return true;
    }
};