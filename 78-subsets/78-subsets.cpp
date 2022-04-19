class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> &subset, int i){
        if(i== nums.size())
            res.push_back(subset);
        else{
            // subset[i]=0;
            helper(nums,subset,i+1); 
            subset.push_back(nums[i]);
            helper(nums,subset,i+1);
            subset.pop_back();
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> subset;
        helper(nums,subset,0);
        ans=res;
        return ans;
    }
};