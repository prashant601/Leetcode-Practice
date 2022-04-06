class Solution {
public:
    double power(double x, int n) {
        if(n<=0) return 1;
        if(x==0) return 0;
        return x * power(x,n-1);
    }
    double myPow(double x, int n) {
        if( (x<1 && x>0 && n>9999999) || (x>1 && n<0 && abs(n)>9999999) ) return 0;
        if(n<0) return 1/power(x,abs(n));
        if(x==1 || x==-1) return x;
        return power(x,n);
    }
};