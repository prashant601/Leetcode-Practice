class Solution {
public:
//     int f(int i, int j, vector<vector<int>>& matrix,int n, vector<vector<int>>&dp ){
//         if(j<0 or j>=n) return 1e9;
//         if(i==0) return matrix[0][j];
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int b= matrix[i][j] + f(i-1,j, matrix, n, dp);
//         int dl= matrix[i][j]+ f(i-1,j+1, matrix, n, dp);
//         int dr= matrix[i][j]+  f(i-1, j-1, matrix, n, dp);
//         return dp[i][j]=min({b,dl,dr});
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n= matrix.size(), mins=1e9;
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // for(int i=0;i<n;i++){
        //     mins= min(mins, f(n-1,i,matrix,n,dp));
        // }
        // return mins;
        
        //tabular
//         int n= matrix.size(), mins=1e9;
//         vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
//         for(int j=0;j<n;j++) dp[0][j]=matrix[0][j]; //initialisation as in base case
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<n;j++){
//                 int b= matrix[i][j] + dp[i-1][j];
//                 int dl= matrix[i][j];
//                 if(j+1<n) dl+= dp[i-1][j+1];  // just for out of bound
//                 else dl+=1e9;
//                 int dr= matrix[i][j];
//                 if(j-1>=0) dr+=dp[i-1][j-1];   // for oob
//                 else dr+=1e9;
//                 dp[i][j]=min({b,dl,dr});
//             }
//         }
//         mins= dp[n-1][0];
//         for(int i=0;i<n;i++) mins=min(mins, dp[n-1][i]);   //getting the min from all starting points 
//         return mins;
        
        //space optimised tabular
        int n= matrix.size(), mins=1e9;
        vector<int> prev(n,0);
        for(int j=0;j<n;j++) prev[j]=matrix[0][j]; //initialisation as in base case
        
        for(int i=1;i<n;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                int b= matrix[i][j] + prev[j];
                int dl= matrix[i][j];
                if(j+1<n) dl+= prev[j+1];  // just for out of bound
                else dl+=1e9;
                int dr= matrix[i][j];
                if(j-1>=0) dr+=prev[j-1];   // for oob
                else dr+=1e9;
                cur[j]=min({b,dl,dr});
            }
            prev=cur;
        }
        mins= prev[0];
        for(int i=0;i<n;i++) mins=min(mins, prev[i]);   //getting the min from all starting points 
        return mins;
        
    }
};