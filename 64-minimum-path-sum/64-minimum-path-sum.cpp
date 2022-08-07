class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>> &dp){
        if(i==0 and j==0) return grid[0][0];
        if(i<0 or j<0) return 1e9; //out of boundary, return max so that it cann't be considered
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up   = grid[i][j]+ f(i-1, j, grid, dp);
        int left = grid[i][j]+ f(i, j-1, grid, dp);
        
        return dp[i][j]= min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return f(m-1, n-1, grid, dp);
    }
};