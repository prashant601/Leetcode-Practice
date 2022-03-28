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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode *> s;
        TreeNode* cur;
        s.push(root);
        while(!s.empty()){
            cur=s.top();
            s.pop();
            if(cur->right!=NULL) s.push(cur->right);
            if(cur->left!=NULL) s.push(cur->left);
            if(!s.empty())
            cur->right=s.top();
            
            cur->left=NULL;
        }
    }
};