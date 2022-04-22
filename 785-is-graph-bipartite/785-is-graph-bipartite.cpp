class Solution {
public:
    bool dfsBipartite(int i,vector<vector<int>> graph, vector<int> &col ){
        if(col[i]==-1) col[i]=1;
        for(auto it:graph[i]){
            if(col[it]==-1){
                col[it]=1-col[i];
                if(!dfsBipartite(it,graph,col)) return false;
            }
            else if(col[it]==col[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> col(V,-1);
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                if(!dfsBipartite(i,graph,col)) return false;
            }
        }
        return true;
    }
};