struct Node{
    Node *links[26];
    bool flag=false;
    
    // checking if reference trie is present or not
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    // creating reference trie
    void put(char ch, Node* node){
        links[ch-'a']= node;
    }
    
    //getting the next node
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    // setting flag true for last referencing trie
    void setEnd(){
        flag=true;
    }
    
    //checking if the word is completed
    bool isEnd(){
        return flag;
    }
    
};

class Trie {
private:
    Node* root;

public:
    
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node * node=root;
        
        for(int i=0;i<word.size();i++){
            if(! node->containsKey(word[i]) ){
                node->put(word[i], new Node());
            }    
            // move to reference trie
            node=node->get(word[i]);
        }
        
        node->setEnd();   // setting the flag of last trie as true
    }
    
    bool checkIfPrefExist(string word){
        bool fl=true;
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            
            node=node->get(word[i]);
            if(node->isEnd()==false) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto word: words){
            trie.insert(word);
        }
        string longest="";
        for(auto it: words){
            if(trie.checkIfPrefExist(it)){
                if(it.size() > longest.size()) {
                    longest = it; 
                }
                else if(it.size()==longest.size() and it<longest)
                    longest=it;
            }
        }
        
        return longest;
    }
};