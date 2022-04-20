class Solution {
public:
    bool isPalindrome(string s) {
        string ns="";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.size();i++){
            int asc=(int)s[i];
            if((asc>=48 && asc<=57)  || asc>=97 && asc<=122  )
                ns+=s[i];
        }
        // cout<<ns;
        int l=0,r=ns.size()-1;
        while(l<r){
            if(ns[l]!=ns[r]) return false;
            l++,r--;
        }
        return true;
    }
};