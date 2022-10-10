class Solution {
public:
    void solve(int op, int cl, string temp, vector<string> &ans ){
        if(op==0 and cl==0){
            ans.push_back(temp);
            return;
        }
        if(cl>0){
            solve(op,cl-1, temp+')', ans);
        }
        if(op>0){
            solve(op-1,cl+1, temp+'(', ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,"", ans);
        return ans;
    }
};