class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=1,c=1;
        set<int> s;
        for(auto i: nums)
            s.insert(i);
        nums.clear();
        for(auto i: s)
            nums.push_back(i);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1)
                c++;
            else
                c=1;
            ans=max(ans,c);
        }
        return ans;
    }
};