class Solution {
public:
//     int mcm(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
//         if(i>j) return 0;   
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int maxi=-1e9;
//         for(int k=i;k<=j;k++){
//             int steps= arr[i-1]*arr[k]*arr[j+1] + mcm(i,k-1,arr,dp) + mcm(k+1,j,arr,dp); // mcm for those two parts
//             maxi=max(maxi,steps);
//         }
//         return dp[i][j]=maxi;
//     }
    int maxCoins(vector<int>& nums) {
        
        // int n= nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(),1);
        // vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        // return mcm(1,n,nums,dp);
        
        //tabular
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2, vector<int> (n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=-1e9;
                for(int k=i;k<=j;k++){
                    int steps= nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]; // mcm for those two parts
                    maxi=max(maxi,steps);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};