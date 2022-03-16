class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,ans=0,mx=0;
        map<int,int>store;
        while(j<nums.size())    
        {
            store[nums[j]]++;
            ans+=nums[j];
            // cout<<"for j "<<nums[j]<<" sum "<<ans<<endl;
            while(store[nums[j]]>1)  
            { 
                // cout<<"for i "<<nums[i]<<" sum "<<ans<<endl;
                store[nums[i]]--;   
                ans-=nums[i];
                i++;
            }
            
            
            mx = max(mx,ans);    
            j++;
        }
        return mx;
    }
};