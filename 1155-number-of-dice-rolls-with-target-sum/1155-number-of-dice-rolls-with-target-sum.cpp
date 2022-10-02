class Solution {
public:
    int f(int n, int k, int target,vector<vector<int>> &dp){
         if (n == 0 || target <= 0) return n == target;
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int res=0;
        for (auto i = 1; i <= k; ++i)
            res = (res + f(n - 1, k, target - i, dp)) % 1000000007;
        
        return dp[n][target]= res;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(35, vector<int>(1005,-1));
        return f(n,k,target,dp);
    }
};