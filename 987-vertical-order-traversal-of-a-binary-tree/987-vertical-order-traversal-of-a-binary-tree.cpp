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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> a(2000),ans;
        queue<pair<TreeNode *,int>> q;
        
        q.push({root,1000});
        
        while(not q.empty()){
            int pos=-1;
            int sz=q.size();
            map<int,vector<int>> mp;
            
            for(int i=0;i<sz;i++){
                
                TreeNode *temp=q.front().first;
                int c=q.front().second;
                q.pop();
                
                mp[c].push_back(temp->val);
                
                if(temp->left){
                    q.push({temp->left,c-1});
                }
                if(temp->right){
                    q.push({temp->right,c+1});
                }
                pos=c;
            }
            
            for(auto it:mp){
                sort(it.second.begin(),it.second.end());
                for(int i=0;i<it.second.size();i++){
                    a[it.first].push_back(it.second[i]);
                }
            }
            
        }
        
        
        for(int i=0;i<2000;i++){
            if(a[i].size()!=0){
                ans.push_back(a[i]);
            }
        }
        
        return ans;
    }
};