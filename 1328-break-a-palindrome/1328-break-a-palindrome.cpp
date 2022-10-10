class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1) return "";
        int n=s.size(), c=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='a' and c==0){
                if(n%2!=0 and i==n/2){
                    ans+=s[i];
                    continue;
                }
                ans+='a';
                c++;
            }
            else
                ans+=s[i];
        }
        
        if(c==0){ // for string like: aaaaaaaa  => aaaaaaab
            ans="";
            for(int i=0;i<n-1;i++)
                ans+=s[i];
            ans+='b';
        }
        return ans;
    }
};