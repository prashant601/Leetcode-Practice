class Solution {
public:
//     int f(int i, int j, vector<vector<int>> &dp){
//         if(i==0 and j==0) return 1;
//         if(i<0 or j<0) return 0; //goes out of bboundary
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int up= f(i-1, j,dp);
//         int left= f(i, j-1,dp);
//         return dp[i][j]=up+left;
//     }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        // return f(m-1,n-1,dp);
        
        //tabular dp
//         vector<vector<int>> dp(m+1, vector<int>(n+1,0));
//         dp[0][0]=1;
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) continue;
//                 int up= 0, left=0;  //else part
//                 if(i>0) up= dp[i-1][j];
//                 if(j>0) left=dp[i][j-1];
//                 dp[i][j]= up+left;
//             }
//         }
//         return dp[m-1][n-1];
                
        //space opt. tabular
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) cur[j]=1;
                else{
                    int up= 0, left=0;
                    if(i>0) up= prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j]= up+left;
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};