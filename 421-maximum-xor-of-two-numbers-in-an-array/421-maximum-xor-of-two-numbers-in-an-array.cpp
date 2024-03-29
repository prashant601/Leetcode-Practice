struct Node{
    Node *links[2];
    
    // checking if reference trie is present or not
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    
    // creating reference trie
    void put(int bit, Node* node){
        links[bit]= node;
    }
    
    //getting the next node
    Node* get(int bit){
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root= new Node();
    }
    
    void insert(int num) {
        Node * node=root;
        
        for(int i=31;i>=0;i--){
            int bit= (num>>i) &  1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit= (num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxNum= maxNum| (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto i:nums)
            trie.insert(i);
        int mx=0;
        for(auto i: nums){
            mx= max(trie.getMax(i), mx);
        }
        return mx;
    }
};