class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), mx=0; // mx is max reachable till now
        for(int i=0;i<n;i++){
            if(i>mx) return false;
            if(i+nums[i]>mx){
                mx= nums[i]+i;
            }
        }
        if(mx>=n-1) return true;
        return false;
    }
};