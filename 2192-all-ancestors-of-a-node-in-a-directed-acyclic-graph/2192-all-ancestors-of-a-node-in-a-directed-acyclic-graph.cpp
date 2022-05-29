class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& graph){
        vis[node]=1;
        for(auto it: graph[node]){
            if(vis[it]==-1)
                dfs(it, vis,graph);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), graph(n);
        
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<n;i++){ //traversing for each node
            vector<int> vis(n,-1);
            dfs(i,vis,graph);    // calling dfs and filling the vis for that node
            
            //if the node is visited in vis, then the present node i is the ancestor of that node 
            for(int j=0;j<n;j++){
                if(i==j) continue; // the node will not be ancestor of itself
                if(vis[j]==1) ans[j].push_back(i);
            }
        }
        return ans;
    }
};