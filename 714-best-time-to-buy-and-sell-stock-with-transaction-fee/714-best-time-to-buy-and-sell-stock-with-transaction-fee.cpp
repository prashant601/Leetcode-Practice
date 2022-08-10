class Solution {
public:
    //buy sell stock II
    int f(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp, int fee){
        if(ind==prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy==1){    // take nottake are profits
            int take= f(ind+1,0,prices,dp,fee) - prices[ind];   //buys is set to 0 , i.e we can only sell
            int nottake= 0+ f(ind+1,1,prices,dp,fee);
            return dp[ind][buy]= max(take, nottake);
        }
        else{
            int sell= prices[ind]+ f(ind+1,1,prices,dp,fee) - fee; // now we can buy again , when sold, trans. completed so the fee will be deducted
            int notsell= 0+ f(ind+1,0,prices,dp,fee); // cannot buy, first sell this
            return dp[ind][buy]= max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1));  // buys is only 0 1 so dp is of n*2
        return f(0,1, prices,dp,fee); // 1 is for buy  
    }
};