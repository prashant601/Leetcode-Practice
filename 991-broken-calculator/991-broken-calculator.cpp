class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int c=0;
        while(target!=startValue && target>startValue){
            if(target%2==0){
                target/=2;
                c++;
            }
            else{
                target++;
                c++;
            }
        }
        if(target!=startValue) c+=abs(target-startValue);
        return c;
    }
};