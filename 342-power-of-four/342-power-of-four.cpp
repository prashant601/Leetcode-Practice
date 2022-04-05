class Solution {
public:
    bool helper(int n,int k){
        if(pow(4,k)==n) return true;
        else if(pow(4,k)> n)  return false;
        return helper(n,k+1);
    }
    bool isPowerOfFour(int n) {
        // return helper(n,0);
        
        if(n==0) return false;
        if(n==1) return true;
        return ( n%4 == 0 && isPowerOfFour(n/4) );
    }
};