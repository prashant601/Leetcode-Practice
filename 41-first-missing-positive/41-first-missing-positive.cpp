class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mx=nums[0];
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
    
        map<int,int> arr;
        arr[1]=0;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        // for(int i=1;i<mx+1;i++){
        //     if(arr[i]==0)
        //         return i;
        // }
        
        if(arr[1]==0) return 1;
        int c=0,l;
        for(auto i: arr){
            if(c==0){
                l=i.first;
                c++;
                continue;
            }
            if(i.first!=l+1 && l+1>0)
                return l+1;
            l=i.first;            
        }
        return mx+1;
    }
};