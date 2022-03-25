class Solution {
private:
    
    int find(int ind, int trans,int n, vector<int>& prices,vector<vector<int>>&dp){
        if(ind==n || trans==4) return 0;
        
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        
        if(trans%2==0)
            return dp[ind][trans]= max(-prices[ind]+find(ind+1,trans+1,n,prices,dp), 0+find(ind+1,trans,n,prices,dp));
        
        else
            return dp[ind][trans]= max(prices[ind]+find(ind+1,trans+1,n,prices,dp), 0+find(ind+1,trans,n,prices,dp));
        
            
    }
public:
    int maxProfit(vector<int>& prices) {
        // int c1=INT_MAX,c2=INT_MAX,p1=0,p2=0;
        // int n=prices.size();
        // for(int i=0;i<n;i++){
        //     c1=min(c1, prices[i]);          //buyprice1 
        //     p1=max(p1,prices[i]-c1);        //profit 1
        //     c2=min(c2,prices[i]-p1);        //buyprice2
        //     p2=max(p2, prices[i]-c2);       //profit 2 is the total profit including p1
        // }
        // return p2;
        
        vector<vector<int>> dp(prices.size()+2, vector<int> (5,-1));
        return find(0,0,prices.size(),prices,dp);
    }
};