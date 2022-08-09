class Solution {
public:
//     int f(int n, int m, string s, string t, vector<vector<int>>&dp){
//         if(m<0) return 1; // all characters matches
//         if(n<0) return 0; // matching for all characters isn't finished yet and main string ends
        
//         if(dp[n][m]!=-1) return dp[n][m];
        
//         if(s[n]==t[m]) return dp[n][m]= f(n-1,m-1,s,t,dp) + f(n-1,m,s,t,dp); // matches, either take that or keep searching
//         else return dp[n][m]= f(n-1,m,s,t,dp); //doesn't match, keep searching
//     }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return f(n-1,m-1,s,t,dp);
        
        //tabular
//         vector<vector<double>> dp(n+1, vector<double>(m+1,0));
//         for(int i=0;i<=n;i++) dp[i][0]=1;
//         // for(int j=0;j<=m;j++) dp[0][j]=0;// no need
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1])
//                     dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
//                 else
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         return (int)dp[n][m];
        
        //space optimized tabular
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=curr[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    curr[j]=prev[j-1]+prev[j];
                else
                    curr[j]=prev[j];
            }
            prev=curr;
        }
        return prev[m];
    }
};