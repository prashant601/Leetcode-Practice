class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        // tabular
        int n= prices.size();
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(2,vector<double>(K+1,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=K;k++){
                    if(j==1){
                        int take= dp[i+1][0][k] - prices[i];   //buys is set to 0 , i.e we can only sell
                        int nottake= 0+ dp[i+1][1][k];
                        dp[i][j][k]= max(take, nottake);   
                    }
                    else{
                        int sell= prices[i]+ dp[i+1][1][k-1]; // now we can buy again
                        int notsell= 0+ dp[i+1][0][k]; // cannot buy, first sell this
                        dp[i][j][k]= max(sell, notsell);
                    }
                }
            }
        }
        return dp[0][1][K];
    }
};