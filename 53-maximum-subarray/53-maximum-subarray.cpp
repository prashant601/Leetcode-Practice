class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long g_max=nums[0],c_max=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            c_max=max(c_max+ (long long)nums[i], (long long)nums[i]);
            g_max=max(g_max,c_max);
        }
        return (int)g_max;
    }
};