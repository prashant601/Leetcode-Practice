class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        if(i==n-1) return triangle[i][j];
        if(i>= n or j>=m) return 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down= triangle[i][j] +  f(i+1, j,n,m,triangle,dp);
        int downright= triangle[i][j] + f(i+1, j+1,n,m,triangle,dp);
        return dp[i][j]=min(down, downright);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); 
        int m= triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(0, 0, n, m, triangle, dp);
    }
};