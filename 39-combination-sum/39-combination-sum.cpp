class Solution {
public:
    vector<vector<int>> ans;
    void check(int ind, vector<int> v, vector<int> &nums, int target, int &n){
        if(ind==n ){
            if(target==0) ans.push_back(v);
            
            return;
        }
        v.push_back(nums[ind]);
        if(nums[ind]<=target){
            check(ind, v, nums, target-nums[ind], n);
        }
        v.pop_back();
        check(ind+1, v, nums, target, n);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int ind=0,n=nums.size();
        vector<int> v;
        check(ind, v, nums, target, n);
        return ans;
    }
};