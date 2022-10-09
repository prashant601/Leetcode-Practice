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
    vector<int> ans;
    void f(TreeNode* root){
        if(root==NULL) return;
        f(root->left);
        ans.push_back(root->val);
        f(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        f(root);
        // for(auto i:ans) cout<<i<<" ";
        int i=0, j= ans.size()-1;
        while(i<j){
            int sm=ans[i]+ans[j]; 
            if(sm== k) return true;
            else if( sm>k){
                j--;
            }
            else
                i++;
        }
        
        return false;
    }
};