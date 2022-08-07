class Solution {
public:
//     int f(int i, int j, int n, int m, vector<vector<int>>& triangle, vector<vector<int>>&dp){
//         if(i==n-1) return triangle[i][j];
//         if(i>= n or j>=m) return 1e9; //no use
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int down= triangle[i][j] +  f(i+1, j,n,m,triangle,dp);
//         int downright= triangle[i][j] + f(i+1, j+1,n,m,triangle,dp);
        
//         return dp[i][j]=min(down, downright);
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // int m= triangle[n-1].size();
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return f(0, 0, n, m, triangle, dp);
        
        //tabular 
//         int n=triangle.size();
//         int m= triangle[n-1].size();
//         vector<vector<int>> dp(n, vector<int>(m,0));
        
//         for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];  // initalization as in base case
        
//         for(int i=n-2;i>=0;i--){
//             for(int j=i;j>=0;j--){
//                 int down= triangle[i][j] + dp[i+1][j];
//                 int downright= triangle[i][j] + dp[i+1][j+1];
//                 dp[i][j]= min(down, downright);
//             }
//         }
        
//         return dp[0][0];
        
        // space optimized tabular
        int n=triangle.size();
        vector<int> prev(n,0);
        
        for(int j=0;j<n;j++) prev[j] = triangle[n-1][j];  // initalization as in base case
        
        for(int i=n-2;i>=0;i--){
            
            vector<int> cur(n,0);
            
            for(int j=i;j>=0;j--){
                int down= triangle[i][j] + prev[j];
                int downright= triangle[i][j] + prev[j+1];
                cur[j]= min(down, downright);
            }
            prev= cur;
        }
        
        return prev[0];
    }
};