class Solution {
public:
    int mx=1, st=0,end=0;
    void getMax(int l, int r, string& s){
        int n=s.size();
        while(l>=0 and r<n){
            if(s[l]==s[r])
                l--,r++;
            else 
                break;
            
            int len= r-l-1;
            if(mx<len){
                mx=len;
                st= l+1;
                end= r-1;
            }
        }
    }
    
    string longestPalindrome(string s) {
        int n= s.size();
        
        for(int i=0;i<n-1;i++){
            getMax(i,i,s);     
        }
        
        for(int i=0;i<n-1;i++){
            getMax(i,i+1,s);
        }
        
        return s.substr(st,mx);
    }
};