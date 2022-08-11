class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        //longest bitonic sequence
        
        int n=nums.size();
        vector<int> dp1(n,1); // for LIS
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    dp1[i]=max(dp1[i], 1+ dp1[j]);
            }
        }
        
        vector<int> dp2(n,1);  // for LDS (LIS of reverse of num)
        for(int i=n-1;i>=0;i--){  
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i])
                    dp2[i]=max(dp2[i], 1+dp2[j]);
            }
        }
        
        // for(auto i:dp1) cout<<i<<" ";
        // cout<<endl;
        //  for(auto i:dp2) cout<<i<<" ";
        int maxi=0;
        
        for(int i=0;i<n;i++){
            if(dp1[i] > 1 && dp2[i] > 1)
                maxi= max(maxi, dp1[i]+dp2[i]-1);  // getting max from bitonic array i.e dp1[i]+dp2[i]-1 
        }
        
        return n-maxi;
    }    
};
// reason for skipping i in lis
//According to question a valley must be present before and after the peak
//Only a mountain with one side is not valid
//                 \               /  These are not valid   /\    Only this is valid
//                  \             /                        /  \
//                   \           /                        /    \
//                    \         /                        /      \