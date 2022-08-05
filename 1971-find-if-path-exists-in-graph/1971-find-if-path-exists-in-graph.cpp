class Solution {
public:
    void dfs(int src, vector<int> &vis, vector<int> adj[] ){
        // storedfs.push_back(src);
        vis[src]=1;
        for(auto i: adj[src]){
            if(vis[i]==0) dfs(i,vis, adj);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> storedfs;
        vector<int> vis(n+1,0);
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(source, vis, adj);
        
        if(vis[destination]==1) return true;
        
        return false;
    }
};