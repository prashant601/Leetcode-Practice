class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
//         int n= nums.size();
//         int mx=nums[0];
//         for(auto i: nums) mx= max(mx, i);
        
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             if(abs(nums[i])>=n ) continue;
            
//             if(nums[abs(nums[i])]<0) 
//                 ans.push_back(abs(nums[i]));
//             else 
//                 nums[abs(nums[i])]*=-1;
//         }
//         return ans;
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
        }
        return res;
    }
};