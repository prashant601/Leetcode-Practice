class Solution {
public:
    bool helper(int n,int k){
        if(pow(3,k)==n) return true;
        else if(pow(3,k)> n)  return false;
        return helper(n,k+1);
    }
    bool isPowerOfThree(int n) {
        return helper(n,0);
        
    }
};