class Solution {
public:
     void helper(vector<char> &s, int k,int n){
        if(k==n/2) return ;
        helper(s,k+1,n);
         swap(s[k],s[n-k-1]);
        
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        helper(s,0,n);
    }
};