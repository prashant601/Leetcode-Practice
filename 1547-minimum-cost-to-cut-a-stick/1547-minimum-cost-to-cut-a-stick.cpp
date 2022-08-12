class Solution {
public:
    int mcm(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
        if(i>j) return 0;  // single matrix, no multip. req
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int steps= (arr[j+1]- arr[i-1])+ mcm(i,k-1,arr,dp) + mcm(k+1,j,arr,dp); // mcm for those two parts
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c= cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());  //[0, ....  ,n]
        vector<vector<int>> dp(c+2, vector<int> (c+2,-1));
        return mcm(1,c,cuts,dp);
        
        
//         int c=cuts.size();
//         vector<vector<double>> dp(c+2, vector<double> (c+2,0));
    
//         for(int i=c;i>=1;i--){
//             for(int j=1;j<=c;j++){
//                 if(i>j) continue;
//                 int mini=1e9;
//                 for(int k=i;k<=j;k++){
//                     int steps= cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j]; // mcm for those two parts
//                     mini=min(mini,steps);
//                 }
//                 dp[i][j]=mini;
//             }
//         }
//         return dp[1][c-1];

    }
};