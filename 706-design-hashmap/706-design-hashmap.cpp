class MyHashMap {
    
public:
    vector<vector<int>> v;
    MyHashMap() {
            // v.clear();
    }
    
    void put(int key, int value) {
        for(auto &i: v){
            if(i[0]==key){
                i[1]= value;
                return;
            }
        }
        v.push_back({key,value});
    }
    
    int get(int key) {
        for(auto &i: v){
            if(i[0]==key){
                return i[1];
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto &i: v){
            if(i[0]==key){
                i[1]=-1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */