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
    
    bool search(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(! node->containsKey(word[i]) )
                return false;
            node= node->get(word[i]);
        }
        
        return node->isEnd() ;  // true if flag of last referen. trie is true(i.e. word exists)  
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if( !node->containsKey(prefix[i]) )
                return false;
            node= node->get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */