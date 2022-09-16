class Solution {
public:
    int f(int k,int i, int n, int m, vector<int> &nums, vector<int>& mult, vector<vector<int>>&dp){
        if(k>=m) return 0;
        
        if(dp[k][i]!=-1) return dp[k][i];
        
        int lv= nums[i]* mult[k];
        int rv= nums[(n-1)-(k-i)]* mult[k];  // we can remove the use of j pointer to optimize
        
        return dp[k][i]= max(lv+ f(k+1,i+1,n,m,nums,mult,dp), rv+ f(k+1,i,n,m,nums,mult,dp));
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n= nums.size(), m= mult.size();
        // vector<vector<int>> dp(m+1 , vector<int> (n+1,-1));
        // return f(0,0, n,m, nums, mult, dp);      
        
        // tabular (recursive giving tle)
        vector<vector<int>> dp(m+1 , vector<int> (m+1,0));
        for(int k=m-1;k>=0;k--){
            for(int i=k;i>=0;i--){
                
                int lv= nums[i]* mult[k];
                int rv=0;
                if((n-1)-(k-i)<n)
                    rv= nums[(n-1)-(k-i)]* mult[k];   
                dp[k][i]= max(lv+ dp[k+1][i+1], rv+ dp[k+1][i]);
            }
        }
        // for(auto i: dp)
        //     for(auto j: i) cout<<j<<" ";
        return dp[0][0];
    }    
};