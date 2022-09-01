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
    int height(Node* root){
        if(root==NULL) return 0;
        
        int mx=0;
        for(auto i: root->children){
            mx= max(mx, height(i));
        }
        return 1+mx;
    }
    int maxDepth(Node* root) {
        int h=0;
        return height(root);        
    }
};