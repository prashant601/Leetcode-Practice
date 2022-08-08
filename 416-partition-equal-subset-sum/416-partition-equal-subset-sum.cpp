// class Solution {
// public:
// //     bool f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp){
// //         if(target==0) return true;
// //         if(ind==0) return (arr[ind]==target);

// //         if(dp[ind][target]!=-1) return dp[ind][target];

// //         bool nottake= f(ind-1, target, arr, dp);
// //         bool take= false;
// //         if(target>=arr[ind])
// //            take= f(ind-1, target- arr[ind], arr, dp);

// //         return dp[ind][target]= (take or nottake);
// //     }
//     // tabular 
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//         vector<vector<bool>>dp(n, vector<bool>(k+1,0));
//         for(int i=0;i<n;i++){
//            dp[i][0]= true;
//         }
//         if(k>=arr[0])
//         dp[0][arr[0]]=true;

//         for(int i=1;i<n;i++){
//             for(int j=1;j<=k;j++){
//                 bool nottake=dp[i-1][j];
//                 bool take= false;
//                 if(j>=arr[i])
//                    take= dp[i-1][j-arr[i]];

//                 dp[i][j]= (take or nottake);
//             }
//         }
//         return dp[n-1][k];
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size(), k=0;
//         for(auto i: nums) k+=i;   // k stores total sum
        
//         if(k%2!=0) return false;  // if total sum cannot be divided into 2 parts return false
        
//         // vector<vector<int>>dp(n+1, vector<int>(k+1,-1));  // use target sum 
//         // return f(n-1, k/2, nums, dp);
//         return subsetSumToK(n, k/2, nums);
//     }
// };
class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum,int N){
        bool dp[N+1][sum+1];
            for(int i=0;i<N+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(i==0) dp[i][j]=false;
                    if(j==0) dp[i][j]=true;
                }
            }
            
            for(int i=1;i<N+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(arr[i-1]<=j)
                        dp[i][j]= (dp[i-1][j-arr[i-1]] || dp[i-1][j] );
                    else
                        dp[i][j]=dp[i-1][j];    
                }
            }
            return dp[N][sum];
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        int N=nums.size();
        for(int i=0;i<N;i++)
        s+=nums[i];
        
        if(s%2!=0)
        return false;
        
        return isSubsetSum(nums,s/2,N);
    }
};