class Solution {
public:
    int mcm(int i,int K, vector<int> &arr, int n,vector<int>&dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int maxi= -1e9,mx=0,len=0;
        for(int k=i; k< min(i+K,n) ;k++){  //since partition is of max size K, so k=i to i+k .  
            len++;
            mx=max(mx,arr[k]);
            int sum= mx*len + mcm(k+1,K,arr,n,dp);
            maxi=max(maxi, sum);
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return mcm(0,k,arr,n,dp);
    }
};