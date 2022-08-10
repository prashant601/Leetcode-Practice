class Solution {
public:
//     int f(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp){
//         if(ind==prices.size()) return 0;
        
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
        
//         if(buy==1){    // take nottake are profits
//             int take= f(ind+1,0,prices,dp) - prices[ind];   //buys is set to 0 , i.e we can only sell
//             int nottake= 0+ f(ind+1,1,prices,dp);
//             return dp[ind][buy]= max(take, nottake);
//         }
//         else{
//             int sell= prices[ind]+ f(ind+1,1,prices,dp); // now we can buy again
//             int notsell= 0+ f(ind+1,0,prices,dp); // cannot buy, first sell this
//             return dp[ind][buy]= max(sell, notsell);
//         }
//     }
    int maxProfit(vector<int>& prices) {
        // int n= prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(3,-1));  // buys is only 0 1 so dp is of n*2
        // return f(0,1, prices,dp); // 1 is for buy   
        
        // // tabular
        // int n= prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<2;j++){
        //         if(j==1){
        //             int take= dp[i+1][0] - prices[i];   //buys is set to 0 , i.e we can only sell
        //             int nottake= 0+ dp[i+1][1];
        //             dp[i][j]= max(take, nottake);   
        //         }
        //         else{
        //             int sell= prices[i]+ dp[i+1][1]; // now we can buy again
        //             int notsell= 0+ dp[i+1][0]; // cannot buy, first sell this
        //             dp[i][j]= max(sell, notsell);
        //         }
        //     }
        // }
        // return dp[0][1];
        
        //tabular dp space optimised
        int n= prices.size();
        vector<int> front(2,0), curr(2,0); // we can use 4 variables
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                    int take= front[0] - prices[i];   //buys is set to 0 , i.e we can only sell
                    int nottake= 0+ front[1];
                    curr[j]= max(take, nottake);   
                }
                else{
                    int sell= prices[i]+ front[1]; // now we can buy again
                    int notsell= 0+ front[0]; // cannot buy, first sell this
                    curr[j]= max(sell, notsell);
                }
            }
            front=curr;
        }
        return front[1];
    }
};


//best solution
// class Solution {           
// public:
//     int maxProfit(vector<int>& prices) {
//         int p=0;
//         for(int i=0;i<prices.size()-1;i++){
//             if(prices[i]<prices[i+1])
//                 p+=prices[i+1]-prices[i];
//         }
//         return p;
//     }
// };