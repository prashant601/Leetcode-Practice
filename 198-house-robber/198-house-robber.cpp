class Solution {
public:
//     int f(int ind,vector<int>&nums, vector<int>&dp){
//         if(ind==0) return nums[ind];
//         if(ind<0) return 0;
        
//         if(dp[ind]!=-1) return dp[ind];
        
//         int pick= nums[ind] + f(ind-2, nums,dp);
//         int  notpick = 0 + f(ind-1, nums,dp);
//         return dp[ind]=max(pick, notpick);
//     }
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp);
        
        
        //tabular
        // int n=nums.size();
        // vector<int> dp(n,0);
        // dp[0]= nums[0];
        // for(int i=1;i<n;i++){
        //     int p= nums[i];
        //     if(i>1)
        //     p+=dp[i-2];
        //     int np= 0 + dp[i-1];
        //     dp[i]= max(p,np);
        // }
        // return dp[n-1];
        
        //space opt. tabular
        int n=nums.size();
        int prev=nums[0],prev2=0,curr;
        for(int i=1;i<n;i++){
            int p= nums[i];
            if(i>1)
            p+=prev2;
            int np= 0 + prev;
            curr= max(p,np);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};
