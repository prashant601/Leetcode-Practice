class Solution {
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return (arr[ind]==target);

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool nottake= f(ind-1, target, arr, dp);
        bool take= false;
        if(target>=arr[ind])
           take= f(ind-1, target- arr[ind], arr, dp);

        return dp[ind][target]= (take or nottake);
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), k=0;
        for(auto i: nums) k+=i;   // k stores total sum
        
        if(k%2!=0) return false;  // if total sum cannot be divided into 2 parts return false
        
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));  // use target sum 
        return f(n-1, k/2, nums, dp);
    }
};