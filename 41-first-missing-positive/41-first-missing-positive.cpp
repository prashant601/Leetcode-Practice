class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // O(n) space approch
//         int mx=nums[0];
//         for(int i=0;i<nums.size();i++){
//             mx=max(mx,nums[i]);
//         }
    
//         map<int,int> arr;
//         arr[1]=0;
//         for(int i=0;i<nums.size();i++){
//             arr[nums[i]]++;
//         }
//         if(arr[1]==0) return 1;
//         int c=0,l;
//         for(auto i: arr){
//             if(c==0){
//                 l=i.first;
//                 c++;
//                 continue;
//             }
//             if(i.first!=l+1 && l+1>0)
//                 return l+1;
//             l=i.first;            
//         }
//         return mx+1;
/////////////////////////////////////////////////////////////////////////////       
        
        // On time O1 space
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;   
    }
};