class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sm=0,last=nums[0],c=0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            if(mp.find(sm-k)!=mp.end())
                c+=mp[sm-k];
            mp[sm]++;
        }
        return c;
    }
};