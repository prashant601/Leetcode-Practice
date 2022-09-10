class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sz= nums.size();
        vector<int> sum(64,0);
        
        for(auto i: nums){
            int ct=0;
            if(i<0)
            {
                i=abs(i);
                sum[32]++;
            }
            while(i>0){
                int bit_i= (i&1) ;
                sum[ct++]+= bit_i;
                i=i>>1;
            }
        }
        
        // for(auto i: sum) cout<<i<<" ";
        
        unsigned int p=1, ans=0;
        for(int i=0;i<=31;i++) {
            sum[i]=sum[i]%3;
            ans+=sum[i]*p;
            p=p<<1;
        }
        if(sum[32]%3==1) ans*=-1;

        return ans;
    }
};