class Solution {
public:
    bool helper(int n,int k){
        if(pow(2,k)==n) return true;
        else if(pow(2,k)> n)  return false;
        return helper(n,k+1);
    }
    bool isPowerOfTwo(int n) {
        return helper(n,0);
        
    }
};