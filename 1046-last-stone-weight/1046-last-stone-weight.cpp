class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        
        for(auto i: stones)
            q.push(i);
        
        int a,b;
        while(q.size()>1){
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            if(a>b) q.push(a-b);
        }
        if(q.size()==1)
        return q.top();
        else return 0;
    }
};