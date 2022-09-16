class CustomStack {
public:
    vector<int> s;
    int max;
    CustomStack(int maxSize) {
        max= maxSize;
    }
    
    void push(int x) {
        if(s.size() < max){
            s.push_back(x);
        }
    }
    
    int pop() {
        if(s.empty()) return -1;
        int last= s.back();
        s.pop_back();
        return last;
    }
    
    void increment(int k, int val) {
        int x= k;
        if(s.size()<k) x= s.size();
        
        for(int i=0;i<x;i++){
            s[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */