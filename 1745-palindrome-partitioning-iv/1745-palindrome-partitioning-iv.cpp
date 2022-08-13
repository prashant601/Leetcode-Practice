class Solution {
public:
    //use dp to store whether given substring is palindrome
    int dp[2001][2001];
    bool isPalin(int i, int j, string& s){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=isPalin(i+1,j-1,s);
        return dp[i][j]=0;
    }
    
    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(isPalin(0,i,s) and isPalin(i+1,j,s) and isPalin(j+1,n-1,s)) return true;
            }
        }
        return false;
    }
};