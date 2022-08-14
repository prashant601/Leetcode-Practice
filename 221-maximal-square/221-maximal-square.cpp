class Solution {
public:
    // same as Count Square Submatrices with All Ones
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m= matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            dp[i][0]=matrix[i][0]-48;
        for(int j=0;j<m;j++)
            dp[0][j]=matrix[0][j]-48;
        
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) +1;
            }

        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                maxi=max(maxi,dp[i][j]);
        }
        return maxi*maxi;
    }
};