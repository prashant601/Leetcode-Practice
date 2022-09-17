class Solution {
public:
    int solve(int i, vector<int>& arr,vector<int> &dp ){
        if(i>=arr.size() or i<0 or arr[i]==-1)
            return false;
        if(arr[i]==0) return true;
        
        if(dp[i]!= -1) return dp[i];
        
        int val= arr[i];
        arr[i]=-1; //marking as visited
        
        return dp[i]= solve(i+val, arr,dp) or solve(i-val,arr,dp);
    }
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        vector<int> dp(n+1,-1);
        return solve(start,arr,dp);
    }
};