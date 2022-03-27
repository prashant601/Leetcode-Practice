class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int dc=0,ind;
        for(int i=0;i<nums.size()-1;i++){
            ind=i-dc;
            cout<<ind<<endl;
            if(ind%2==0 && nums[i]==nums[i+1]){
                dc++;
            }
        }
        if((nums.size()-dc)%2!=0) dc++;
        return dc;
    }
};