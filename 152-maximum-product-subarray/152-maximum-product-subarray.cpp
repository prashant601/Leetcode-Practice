class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long cur_max=1, cur_min=1, res=nums[0];
        for(int i=0;i<nums.size();i++){
            res=max(res,(long long)nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
            long long temp= cur_max*nums[i];
            cur_max=max({cur_max*nums[i], cur_min*nums[i], (long long)nums[i]});
            cur_min=min({temp, cur_min*nums[i], (long long)nums[i]});
            res=max(res,cur_max);
        }
        return res;
    }
};