class Solution {
public:
    bool isPalindrome(int i, int j, string&s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    int mcm(int i, int j, string &s,vector<vector<int>> &dp){
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini= 1e9;
        for(int k=i;k<=j;k++){
            if(isPalindrome(i,k,s)){
                int cost= 1+ mcm(k+1,j,s,dp);  //mcm is for checking right partition palindrome (as left one is)
                mini=min(cost, mini);
            }
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return mcm(0,n,s,dp) -1 ;  //-1 is for excluding the last partition (ex. in ABC=>  A|BC => A| (B|C) => A| B| C| ) we need to exclude the partition after C
    }
};