class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n= nums.size(), s=0;
        for(int i=0;i<n;i++){
            s+= nums[i]%2==0 ? nums[i]: 0; 
        }
        vector<int> ans;
        for(auto i: q){
            int val= i[0];
            int ind= i[1];
            if( nums[ind]%2==0 )
                s-=nums[ind];
            
            nums[ind]+=val;
            
            if( nums[ind]%2==0 )
                s+=nums[ind];
            
            ans.push_back(s);
        }
        return ans;
    }
};