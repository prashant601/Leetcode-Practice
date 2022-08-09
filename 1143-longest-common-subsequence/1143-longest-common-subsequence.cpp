class Solution {
public:
//     int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>>&dp){
//         if(ind1<0 or ind2<0) return 0;
        
//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
//         if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]= 1+f(ind1-1, ind2-1, s1, s2, dp); // if matches 
//         else return dp[ind1][ind2]= max(f(ind1-1,ind2,s1,s2,dp), f(ind1, ind2-1,s1,s2,dp)); // not matches, shrink the string
        
//     }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        // vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));
        // return f(n1-1, n2-1, s1, s2, dp);
        
//         //tabular
//         vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));
         
//         // shifting of index i.e for -1 use 0, 
//         for(int j=0;j<=n2;j++) dp[0][j]=0;
//         for(int i=0;i<=n1;i++) dp[i][0]=0;   // initialisation using base case
        
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 if(s1[i-1]==s2[j-1]){ //due to shifting of index
//                     dp[i][j]= 1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
//         return dp[n1][n2];
        
        // space optimized tabular
         vector<int> prev(n2+1,0), curr(n2+1,0);
        // shifting of index i.e for -1 use 0, 
        for(int j=0;j<=n2;j++) prev[j]=0;
        // initialisation using base case
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){ //due to shifting of index
                    curr[j]= 1+prev[j-1];
                }
                else{
                    curr[j]= max(curr[j-1], prev[j]);
                }
            }
            prev=curr;
        }
        return prev[n2];
        
    }
};