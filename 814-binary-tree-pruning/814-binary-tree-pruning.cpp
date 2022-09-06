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
    bool solve(TreeNode* root){
        if(root==NULL) return false;
        
        bool leftCont= solve(root->left);
        bool rightCont = solve(root->right);
        
        if(leftCont==false) root->left=NULL;
        if(rightCont==false) root->right=NULL;
        
        return root->val==1 || leftCont || rightCont;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool s= solve(root);
        return s==true? root: NULL ;
    }
};