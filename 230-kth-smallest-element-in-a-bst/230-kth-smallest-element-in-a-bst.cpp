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
    TreeNode* ans;
    void inorder(TreeNode* root, int &k){
        if(root==NULL) return;
        inorder(root->left, k);
        k--;
        if(k==0){
            ans=root;  
        }
        // cout<<root->val<<"  "<<k<<endl;
        if(ans==NULL) inorder(root->right,k); 
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp;
        inorder(root,k);
        temp=ans;
        return ans->val;
    }
};