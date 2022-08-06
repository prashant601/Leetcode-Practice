class Solution {
public:
    int climb(int n, vector<int>&dp){
        if(n==0) return dp[n]=1;
        if(n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= climb(n-1,dp) + climb(n-2,dp);
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<dp.size();i++) dp[i]=-1;
        
        return climb(n,dp);
    }
};