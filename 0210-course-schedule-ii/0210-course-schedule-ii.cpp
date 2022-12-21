class Solution {
public:
    stack<int> s;
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
                s.push(node);
               return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
       vector<int> adj[n];
        vector<int> ans;
        for(auto i: pre){
            adj[i[1]].push_back(i[0]);
        }
        
        // for(auto i:indeg){
        //     if(i==0) q.push(i);
        // }
          
        vector<int> vis(n,0), dfsVis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(isCycle(i, adj, vis, dfsVis)) return {};
            }
        }
        for(int i=0;i<n;i++){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};