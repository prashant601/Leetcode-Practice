class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s2.empty()){
            int x=s2.top();
            s2.pop();
            s1.push(x);
        }
        s2.push(x);
        while(!s1.empty()){
            int x=s1.top();
            s1.pop();
            s2.push(x);
        }
    }
    
    int pop() {
        if(s2.empty()) return -1;
        int first= s2.top();
        s2.pop();
        return first;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */