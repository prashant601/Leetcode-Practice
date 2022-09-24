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
    bool solve(TreeNode* root, int target){
        if(root==NULL) return false;
        if(root->val==target and root->left==NULL and root->right==NULL) return true;
        return solve(root->left, target-root->val) or solve(root->right, target- root->val); 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // int sum=0;
        return solve(root, targetSum);
    }
};