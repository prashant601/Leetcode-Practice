class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s= to_string(n);
        int ind, len;
        len=s.size();
        ind=len;
        for(int i=len-1;i>=1;i--){
            if(s[i]<s[i-1]){
                ind=i;
                s[i-1]--;
            }
        }
        for(int i=ind;i<len;i++) s[i]='9';
        return stoi(s);
    }
};