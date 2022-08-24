class Solution {
public:
    int next(int n){
        int d,ans=0;
        while(n){
            d=n%10;
            ans+=d;
            n=n/10;
        }
        return ans;
    }
    int addDigits(int num) {
        if(num/10==0) return num;
        int ans=0;
        while(num/10!=0){
            num=next(num);
            ans=num;
        }
        return ans;
    }
};