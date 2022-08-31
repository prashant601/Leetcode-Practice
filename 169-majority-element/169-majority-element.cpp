class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int maj=0;
        for(int i=0;i<nums.size();i++){
            if(c==0)
                maj=nums[i];
            if(nums[i]==maj)
                c+=1;
            else c+=-1;
        }
        return maj;
    }
};