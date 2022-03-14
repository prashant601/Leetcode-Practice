class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;

        int dif=0,prev_dif=nums[1]-nums[0],ind=0,c=0;
        for(int i=1;i<n-1;i++){
            dif=nums[i+1]-nums[i];
            if(dif==prev_dif){
                ind++;
            }
            else{
                prev_dif=dif;
                ind=0;   
            }
            c+=ind;
        }
        return c;
    }
};