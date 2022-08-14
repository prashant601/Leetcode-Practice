class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        int f,s,t,a;
        f=0,s=1,t=1;
        for(int i=3;i<n+1;i++){
            a=f+s+t;
            f=s, s=t, t=a;
        }
        return a;
    }
};