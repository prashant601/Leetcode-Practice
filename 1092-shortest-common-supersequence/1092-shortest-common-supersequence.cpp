class Solution {
public:
    int lcs(int n, int m, string s1, string s2, vector<vector<int>>& dp){
        // using tabular method
        
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0; // shifting of index, this case is for -ve values of ind in recursion
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){ // -1 is due to shifting of index
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m]; //this returns the length of lcs
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        int len = lcs(n,m,s1,s2,dp);  // returns the len of lcs of s1 s2

        string ans="";            
        int i=n,j=m;
        while(i>0 and j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]> dp[i][j-1]){
                ans+= s1[i-1];
                i--;
            }
            else{
                ans+= s2[j-1];
                j--;
            }
        }
        
        //if any i (for s1)  or j (for s2) becomes <0, loop breaks, so add remaining part of string in ans
        
        while(i>0)    ans+=s1[i-1],i--;
        while(j>0)    ans+=s2[j-1],j--;
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};