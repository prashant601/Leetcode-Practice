class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stk.push(i);
            else if(s[i]==')'){
                if(!stk.empty()) stk.pop();
                else s[i]='*';
            }
        }
        
        while(!stk.empty()){
            s[stk.top()]='*';
            stk.pop();
        }
        for(int i=0;i<s.size();i++) {
            if(s[i]=='*') continue;
            ans+=s[i];
            }
        return ans;
    }
};