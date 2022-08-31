class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int k=n/3;
        map<int,int> mp;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        
        vector<int> ans;
        for(auto i:mp) if(i.second>k) ans.push_back(i.first);
        return ans;
    }
};