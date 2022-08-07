class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix,int n, vector<vector<int>>&dp ){
        if(j<0 or j>=n) return 1e9;
        if(i==0) return matrix[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int b= matrix[i][j] + f(i-1,j, matrix, n, dp);
        int dl= matrix[i][j]+ f(i-1,j+1, matrix, n, dp);
        int dr= matrix[i][j]+  f(i-1, j-1, matrix, n, dp);
        return dp[i][j]=min({b,dl,dr});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size(), mins=1e9;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mins= min(mins, f(n-1,i,matrix,n,dp));
            // dp.clear();
        }
        return mins;
    }
};