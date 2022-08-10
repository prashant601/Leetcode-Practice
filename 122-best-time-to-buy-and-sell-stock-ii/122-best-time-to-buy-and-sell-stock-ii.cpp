class Solution {
public:
    int f(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy==1){    // take nottake are profits
            int take= f(ind+1,0,prices,dp) - prices[ind];   //buys is set to 0 , i.e we can only sell
            int nottake= 0+ f(ind+1,1,prices,dp);
            return dp[ind][buy]= max(take, nottake);
        }
        else{
            int sell= prices[ind]+ f(ind+1,1,prices,dp); // now we can buy again
            int notsell= 0+ f(ind+1,0,prices,dp); // cannot buy, first sell this
            return dp[ind][buy]= max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1));  // buys is only 0 1 so dp is of n*2
        return f(0,1, prices,dp); // 1 is for buy   
    }
};