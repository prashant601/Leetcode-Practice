class Solution {
public:
    int houserob1(vector<int>&nums){
        //space opt. tabular
        int n=nums.size();
        int prev=nums[0],prev2=0,curr;
        for(int i=1;i<n;i++){
            int p= nums[i];
            if(i>1)
            p+=prev2;
            int np= 0 + prev;
            curr= max(p,np);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> t1,t2;
        int n=nums.size();
        
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        for(int i=0;i<n;i++){
            if(i!=0) t1.push_back(nums[i]) ;  // excluding 1st element
            if(i!=n-1) t2.push_back(nums[i]);  // excluding only last element
        }
        return max( houserob1(t1), houserob1(t2));
    }
};