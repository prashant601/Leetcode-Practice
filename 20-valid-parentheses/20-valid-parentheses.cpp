class Solution {
public:
    bool isValid(string x) {
        stack<char> s;
        for(int i=0;i<x.size();i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '[')
            s.push(x[i]);
            else if(x[i] == ')' || x[i] == '}' || x[i] == ']'){
                if(s.empty() || (s.top()=='{' && x[i]!='}') || (s.top()=='[' && x[i]!=']') |(s.top()=='(' && x[i]!=')') )
                return false;
                else
                s.pop();
            }
        }
        if (s.empty())
        return true;
        else
        return false;
    }
};