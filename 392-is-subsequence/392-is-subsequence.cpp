class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0,l2=0,n=s.size()-1,m=t.size()-1;
        while(l<=n && l2<=m){
            if(s[l]==t[l2]){
                l++; l2++;
            }
            else
                l2++;
        }
        if(l==n+1 || n<0) return true;
        return false;
    }
};