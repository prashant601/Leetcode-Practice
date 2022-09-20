class Solution {
public:
    bool isUgly(int n) {
        int n1=n;
        // n=abs(n);
        if(n<=0) return false;
        int i=2;
            while(n%i==0){
                n=n/i;
            }
        i=3;
            while(n%i==0){
                n=n/i;
            }
          i=5;
            while(n%i==0){
                n=n/i;
            }
        
        if(n!=1)
            return false;
        return true;
    }
};