class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> subset, int i){
        if(i== nums.size())
            res.push_back(subset);
        else{
            // subset[i]=0;
            helper(nums,subset,i+1); 
            subset.push_back(nums[i]);
            helper(nums,subset,i+1);
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(nums,subset,0);
        ans=res;
        
        map<vector<int>,int> mp;
        for(auto &i: ans){
            mp[i]++;
            }
        ans.clear();
        for(auto &i: mp){
            ans.push_back(i.first);
        }
        return ans;
    }
};