class Solution {
public:
//     int numDecodings(int p, string& s) {
//         int n = s.size();
//         if(p == n) return 1;
//         if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
//         int res = numDecodings(p+1,s);
//         if( p < n-1 && ( s[p]=='1'|| ( s[p]=='2'&& s[p+1]<'7') ) ) res += numDecodings(p+2,s);
//         return res;
//     }
    
    int numDecodings(string s) {
        if(s.empty()) 
            return 0;
        
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return p;   
    }
    
};