class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        int f1=1,f2=1,f3=1;
        for(int i=2;i<=n;i++){
            dp[i]= min({2* dp[f1], 3*dp[f2], 5*dp[f3]});
            if(dp[i]== 2* dp[f1]) f1++;
            if(dp[i]== 3* dp[f2]) f2++;
            if(dp[i]== 5* dp[f3]) f3++;
        }
        return dp[n];
    }
};