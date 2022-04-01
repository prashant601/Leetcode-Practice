class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//         int v=nums[0],n=nums.size(), m=1,c=1;
//         for(int i=0;i<n;i++){
//             v=nums[i];
//             for(int j=i;j<n;j++){
//                 if(v<nums[j]){
//                     c++;
//                     v=nums[j];
//                 }
                
//                 m=max(m,c);
//             }
//             c=1;
//         }
//         return m;
        int n=nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int m=dp[0];
        for(auto i:dp)
            m=max(m,i);
        return m;
        
    }
};