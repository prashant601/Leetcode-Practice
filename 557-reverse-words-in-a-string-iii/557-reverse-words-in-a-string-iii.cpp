class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') 
                t+=s[i];
            
            if(i< s.size()-1 and s[i+1]==' ')
            {
                ans.push_back(t);
                t="";
            }
        }
        string res="";
        ans.push_back(t);
        for(auto u:ans){
            reverse(u.begin(),u.end());
            res+=u+" ";
        }
        
        return res.substr(0,res.size()-1);
    }
};