class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int a=0,b=0;
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        int mx=1;
        for(int i=0;i<n;i++){
           dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
           dp[i][i+1]= (s[i]==s[i+1])? 1: 0 ;
            if(dp[i][i+1]==1){
                mx=2;
                a=i;
                b=i+1;
            }
        
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                dp[i][i+len-1]= (s[i]==s[i+len-1] and dp[i+1][i+len-2]) ? 1 : 0;
                if(dp[i][i+len-1]==1 and mx< len){
                    a= i,b= i+len-1;
                    mx=max(mx, len);
                }
            }
        }
        return s.substr(a, b-a+1);
    }
};