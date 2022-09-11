class Solution {
public:
    string reverseWords(string s) {
        string ans="", t="";
        vector<string> v;
        for( char i : s){
           if(i!=' ')
               t+=i;
            else{
                if(t!="")
                v.push_back(t);
                t="";
            }
        }
        if(t!="")
        v.push_back(t);
        
        // for(auto i: v) cout<<i<<"%";
        
        // cout<<endl;
        for(int i=v.size()-1;i>=1;i--) ans+=v[i]+" ";
        ans+= v[0];
        return ans;
    }
};