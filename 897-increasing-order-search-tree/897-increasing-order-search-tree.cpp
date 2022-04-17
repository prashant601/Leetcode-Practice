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
    TreeNode* temp;
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
        root->left=NULL;
        temp->right=root;
        temp=root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode* ans = new TreeNode(0);
        temp=ans;
        inorder(root);
        return ans->right;
    }
};