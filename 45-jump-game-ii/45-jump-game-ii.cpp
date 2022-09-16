class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1]=0;
        for(int i= n-2;i>=0;i--){
            int mn= INT_MAX;
            for(int j= i+1; j<= min(n-1, i+nums[i]);j++){
                mn= min(mn, dp[j]);
            }
            if(mn!=INT_MAX)
                dp[i]= mn+1;
        }
        return dp[0];
    }
};