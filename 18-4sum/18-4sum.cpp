class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),start=0,end,sum1=target;
        set<vector<int>> ans; 
        vector<vector<int>> res; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                start=j+1,end=n-1;
                while(start<end){
                    if(nums[start]+nums[end]==sum1-nums[i]-nums[j]){
                        ans.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                    }
                    else if(nums[start]+nums[end]<sum1-nums[i]-nums[j])
                        start++;
                    else 
                        end--;
                }
            }
        }
        for(auto &i: ans){
            res.push_back(i);
        }
        
        return res;
    }
};