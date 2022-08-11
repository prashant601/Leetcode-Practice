class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1), cnt(n,1);
        int maxi=1; //stores length of lis
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] and dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j]; //inherit the cnt
                }
                else if( nums[j]<nums[i] and dp[i]==1+dp[j])
                    cnt[i]+=cnt[j]; //increase the cnt
            }
            maxi=max(maxi,dp[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++) if(dp[i]==maxi) ans+=cnt[i];
        return ans;
    }
};