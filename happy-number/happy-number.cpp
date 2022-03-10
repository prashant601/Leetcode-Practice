class Solution {
private:
    int next(int n){
        int a,sm=0;
        while(n!=0){
            a=n%10;
            n=n/10;
            sm+=a*a;
        }
        return sm;
    }
public:
    bool isHappy(int n) {
        int a;
        set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n=next(n);
        }
        return n==1;
    }
};