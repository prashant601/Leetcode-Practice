class Solution {
public:
//     int mcm(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
//         if(i==j) return 0;  // single matrix, no multip. req
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int mini=1e9;
//         for(int k=i;k<=j-1;k++){
//             int steps= arr[i-1]*arr[k]*arr[j] + mcm(i,k,arr,dp) + mcm(k+1,j,arr,dp); // mcm for those two parts
//             mini=min(mini,steps);
//         }
//         return dp[i][j]=mini;
//     }
    int minScoreTriangulation(vector<int>& values) {
        // int n= values.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        // return mcm(1,n-1,values,dp);
        
        // tabular
        int n= values.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
    
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int steps= values[i-1]*values[k]*values[j] + dp[i][k] + dp[k+1][j]; // mcm for those two parts
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};