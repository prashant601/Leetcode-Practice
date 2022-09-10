class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res=0;
        
        for(auto i: nums)
            res= res^i;
        
        int temp= res;
        int pos=0;
        
        while( (temp&1)!=1 ){  // finding the first set bit
            pos++;
            temp=temp>>1;
        }
        
        int mask= (1<<pos);  // creating mask like 00010000
        int n1=0,n2=0;
        for(auto i: nums){
            if( (mask&i) > 0)
                n1=n1^i;      // geting values that have set bit at that pos and taking xor
        }
        
        // repeated value will cancel out from xor and 1st no. will be left
        n2= res^n1;    // since res was n1^n2,  n1 will cancel out
        
        return {n1,n2};
    }
};