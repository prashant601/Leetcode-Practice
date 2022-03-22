class Solution {
public:
    int countHillValley(vector<int>& a) {
        int c=0;
        vector<int> nums;
        nums.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1])
                nums.push_back(a[i]);
        }
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]!=nums[i] && nums[i]!=nums[i+1] ){
                if(nums[i]==max({nums[i],nums[i-1],nums[i+1]})){
                    c++;
                }
                else if(nums[i]==min({nums[i],nums[i-1],nums[i+1]}))
                    c++;
            }
        }
        return c;
    }
};