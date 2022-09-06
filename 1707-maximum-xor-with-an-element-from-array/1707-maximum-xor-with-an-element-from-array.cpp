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
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qr) {
        sort(nums.begin(),nums.end());
        
        Trie trie;
        vector<vector<int>> q;
        
        for (int i = 0; i < qr.size(); i++) {
            auto v = qr[i];
            q.push_back({v[1], v[0], i});  // also store the index coz it gets rearranged after sort
        }
        
        sort(q.begin(), q.end());
        
        int j = 0;
        vector<int> res(qr.size());
        
        for (auto& p : q) {
            int x = p[1];
            int threshold = p[0];
            
            while (j < nums.size() && nums[j] <= threshold) {
                trie.insert(nums[j]);
                j++;
            }
            if(j==0) res[p[2]]=-1;
            else res[p[2]] = trie.getMax(x);
        }
        return res;
    }
};