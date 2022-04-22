// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // vector<int> ans;
        // queue<int> q;
        // vector<int> vis(V,0);
        // q.push(0);
        // vis[0]=1;
        // while(!q.empty()){
        //     int a=q.front();
        //     q.pop();
        //     ans.push_back(a);
        //     for(auto i: adj[a]){
        //         if(vis[i]==0){
        //             q.push(i);
        //             vis[i]=1;
        //         }
        //     }
        // }
        // return ans;
        vector<int> bfs;
        vector<int> vis(V,0);
        
        // for(int i=0;i<V;i++){
        int i=0;
            if(vis[i]){
                queue<int> q;
                q.push(vis[i]);
                
                vis[i]=1;
                while(!q.empty())
                {
                    int node =q.front();
                    q.pop();
                    bfs.push_back(node);
                    
                    for(auto it: adj[node]){
                        if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                        }
                    }
                }
            // }
        }
        return bfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends