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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp= new TreeNode(val);
            temp->left= root;
            return temp;
        }
        
        queue<TreeNode*> q;
        vector<TreeNode*> l;
        int lvl=2;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            for(int i=0;i<n;i++){
                TreeNode* node= q.front();
                q.pop();
                if(lvl==depth){
                    l.push_back(node);
                }
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            lvl++;
        }
        // for(auto i: l) cout<<i->val;
        
        for(auto &node: l){
            TreeNode* temp1= node->left;
            TreeNode* temp2= node->right;
            node->left= new TreeNode(val);
            node->left->left= temp1;
            node->right= new TreeNode(val);
            node->right->right= temp2;
        }
        
        return root;
    }
};