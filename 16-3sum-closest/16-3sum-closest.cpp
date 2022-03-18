class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l,r=nums.size()-1,near=INT_MAX,s=target, ans=0;
        for(int i=0;i<nums.size();i++){
            l=i+1,r=nums.size()-1;
            while(l<r){
                // cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<endl;
                if(nums[l]+nums[r]==s-nums[i]){
                    return nums[i]+nums[l]+nums[r];
                    l++;
                }
                else if(nums[l]+nums[r]>s-nums[i]){
                    if(near>abs(nums[l]+nums[r]+nums[i]-target))
                        near=abs(nums[l]+nums[r]+nums[i]-target) , ans=nums[i]+nums[l]+nums[r] ;
                    r--;
                }
                else{
                    if(near>abs(nums[l]+nums[r]+nums[i]-target))
                        near=abs(nums[l]+nums[r]+nums[i]-target) , ans=nums[i]+nums[l]+nums[r] ;
                    l++;
                }
            }
        }
        
        return ans;
    }
};