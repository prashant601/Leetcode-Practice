class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>>&dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]= (s[i]==s[j] ? solve(s,i+1,j-1,dp) : 0 );
    }
    int countSubstrings(string s) {
        int ans=0, n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        for(int i=0;i<s.size();i++){   //checking all substrings (n*n)
            for(int j=i;j<s.size();j++){
                ans+= solve(s,i,j,dp);
            }
        }
        return ans;
    }
};