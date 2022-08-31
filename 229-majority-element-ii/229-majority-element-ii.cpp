class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         int k=n/3;
//         map<int,int> mp;
        
//         for(int i=0;i<n;i++) mp[nums[i]]++;
        
//         vector<int> ans;
//         for(auto i:mp) if(i.second>k) ans.push_back(i.first);
//         return ans;
        
        
        //moore's algo
        
        int n=nums.size();
        int num1=INT_MIN, num2=INT_MIN, count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==num1)
                count1++;
            else if( nums[i]==num2)
                count2++;
            else if( count1==0)
                num1=nums[i], count1=1;
            else if( count2==0)
                num2=nums[i],count2=1;
            else 
                count1--,count2--;
        }
        // there will be max 2 majority element (either num1 or num2)
        
        count1=count2=0;
        for(auto i:nums){
            if(i==num1) count1++;
            else if(i==num2) count2++;
        }
        vector<int>ans;
        if(count1>n/3) ans.push_back(num1);
        if(count2>n/3) ans.push_back(num2);
        return ans;
        
    }
};