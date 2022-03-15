class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         long long cur_max=1, cur_min=1, res=nums[0];
        
//         for(int i=0;i<nums.size();i++){
//             long long temp= cur_max*nums[i];
//             cur_max=max({cur_max*nums[i], cur_min*nums[i], (long long)nums[i]});
//             cur_min=min({temp, cur_min*nums[i], (long long)nums[i]});
//             res=max(res,cur_max);
//         }
//         return res;
        
        //approach 2
        int mx=nums[0], prod=1, n=nums.size();
        for(int i=0;i<n;i++){
            prod*=nums[i];
            mx=max(prod,mx);
            if(nums[i]==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            mx=max(mx,prod);
            if(nums[i]==0) prod=1;
        }
        return mx;
        
    }
};