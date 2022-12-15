class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>&vis, int &cnt){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                dfs(it, adj,vis, cnt);
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> ind(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)
                adj[i].push_back(leftChild[i]);
             if(rightChild[i]!=-1)
                adj[i].push_back(rightChild[i]);
        }
        
        vector<int> vis(n,0);
        int cnt=0;
        
        
    
        
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                ind[leftChild[i]]++;
            }
             if(rightChild[i]!=-1){
                ind[rightChild[i]]++;     
             }
        }
        int src=0;
        for(int i=0;i<n;i++){
            if(ind[i]==0) {
                src=i;
                break;
            }
        }
        dfs(src,adj,vis,cnt);
        for(auto i: vis){
            if(i==0) return false;
        }
        cnt=0;
        // for(auto i:ind) cout<<i<<" ";
        for(auto i:ind){
            
            if(i==0) cnt++;
            if(i>1) return false;
        }
        // cout<<"cnt "<<cnt;
        if(cnt!=1) return false;
        return true;
    }
};