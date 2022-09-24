/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans){
        if(root==NULL) return ;
        
        path.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL and root->val== target) // is leaf and sum is equal for that path
            ans.push_back(path);
        
        else{
            dfs(root->left, target- root->val, path, ans );
            dfs(root->right, target- root->val, path, ans );
        }
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);
        return ans;
    }
};