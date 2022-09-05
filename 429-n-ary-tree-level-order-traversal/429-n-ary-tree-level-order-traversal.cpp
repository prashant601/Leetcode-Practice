/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int count= q.size();
            for(int i=0;i<count;i++){
                Node* temp= q.front();
                q.pop();
                v.push_back(temp->val);

                for(auto i: temp->children){
                    if(i!=NULL)
                        q.push(i);
                }
            }
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};