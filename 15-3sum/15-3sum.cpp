class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;
    vector<int> v(3, INT_MIN);
    
    for(int i = 0; i < n; i++)
    {
        if(i && nums[i] == nums[i - 1])
            continue;
        
        int a = -nums[i];
        int j = i + 1, k = n - 1;
        while(j < k)
        {                
            if(nums[j] + nums[k] < a)
                j++;
            else if(nums[j] + nums[k] > a)
                k--;
            else
            {
                // ans.push_back({nums[i],nums[j],nums[k]});
                if(v[1] != nums[j] || v[2] != nums[k])
                {
                    v[0] = nums[i], v[1] = nums[j], v[2] = nums[k];
                    ans.push_back(v);
                }
                
                j++, k--;
            }
        }  
    }
    
    return ans;
    }
};