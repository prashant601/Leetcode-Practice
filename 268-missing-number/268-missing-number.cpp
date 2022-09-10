class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int s= nums.size(),sm=0;
        for(auto i:nums) sm= sm+i;
        return (s*(s+1))/2 -sm;  
    }
};