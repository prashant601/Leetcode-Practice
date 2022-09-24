class Solution {
public:
    void dfs(TreeNode* root, vector<int> &path, vector<vector<int>>&ans){
        if(root==NULL) return ;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL){
            ans.push_back(path);
        }
        else{
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
        
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<string> res;
        vector<int> path;
        dfs(root, path, ans);
        for(auto i: ans){
            string t="";
            for(auto j: i){
                t+=to_string(j);
                t+="->";
            }
            if(!t.empty()){
                t.pop_back();
                t.pop_back();
            }
            res.push_back(t);
        }
        return res;
    }
};