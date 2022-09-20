class Solution {
public:
    bool isPerSq(int n){
        int sq= sqrt(n);
        return sq*sq==n;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        vector<int> sq;
        sq.push_back(1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(isPerSq(i)){
                dp[i]=1;
                sq.push_back(i);
            }
            else{
                for(auto j: sq){
                    dp[i]= min(dp[i], dp[i-j]+1);
                }
            }
        }
        return dp[n];
    }
};