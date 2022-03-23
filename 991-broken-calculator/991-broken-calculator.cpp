class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int c=0;
        while(target!=startValue){
            if(target%2==0 && target>startValue){
                target/=2;
                c++;
                if(target+1==startValue){
                    c++;
                    break;
                }
            }
            else{
                target++;
                c++;
            }
        }
        return c;
    }
};