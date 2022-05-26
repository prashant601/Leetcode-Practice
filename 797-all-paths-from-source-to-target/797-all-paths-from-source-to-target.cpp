class Solution {
public:
    void dfs(int src, int dest, vector<vector<int>> &graph, vector<int>& storedfs, vector<vector<int>>& ans){
        storedfs.push_back(src);
        if(src==dest) ans.push_back(storedfs);
        for(auto i: graph[src]){
                dfs(i, dest, graph, storedfs, ans);
                storedfs.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> storedfs;
        vector<vector<int>> ans;  // no need of vis as we need to backtrack 
        dfs(0, n-1, graph, storedfs, ans);
        
        return ans;
    }
};