class Solution {
public:
    //same quest.  Partitions With Given Difference
    //https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0
    
    int f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp){ 
        //modified version of subset sum equal to k (number of subsets)

        // if(target==0) return 1;
        // if(ind==0) return (arr[ind]==target);  // not work for 0 in arr
    
        if(ind==0){
            if(arr[ind]==0 and target==0) return 2; //2 ways, by taking and not taking it
            if(target==0 or target==arr[ind]) return 1; // only 1 way , by not taking it 
            return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int nottake= f(ind-1, target, arr, dp);
        int take= 0;
        if(target>=arr[ind])
           take= f(ind-1, target- arr[ind], arr, dp);

        return dp[ind][target]= (take + nottake);
    }

    int findTargetSumWays(vector<int>& arr, int d) {
        int totSum=0,n=arr.size();
        for(auto &it:arr) totSum+=it;
        
        if( (totSum-d)<0  or (totSum-d)%2!=0) return 0;
        
        vector<vector<int>>dp(n+1, vector<int>(totSum+1,-1));
        return f(n-1,(totSum-d)/2 , arr, dp);
    }
};