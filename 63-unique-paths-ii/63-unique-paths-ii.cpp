class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obs, vector<vector<int>> &dp){
        if(i>=0 and j>=0 and obs[i][j]==1) return 0; //there is an obstacle
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0; //goes out of boundary
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up= f(i-1, j, obs, dp);
        int left= f(i, j-1, obs, dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n= obs[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        
        return f(m-1,n-1,obs,dp);
    }
};