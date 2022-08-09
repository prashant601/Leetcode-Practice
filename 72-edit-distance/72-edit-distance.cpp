class Solution {
public:
    int f(int i, int j, string w1, string w2,vector<vector<int>>&dp){
        if(i<0) return j+1; //no more chars left, so add the remaining string which needs to match
        if(j<0) return i+1; // here, delete the leftover chars  
        
        if(dp[i][j]!=-1) return dp[i][j];
            
        if(w1[i]==w2[j]) return dp[i][j]=0+f(i-1,j-1,w1,w2,dp); // if matches, shrink the string and check
        else{
            int t1= 1+ f(i,j-1,w1,w2,dp); // for insertion
            int t2= 1+ f(i-1,j,w1,w2,dp); //for deletion
            int t3= 1+ f(i-1,j-1,w1,w2,dp); // for replace
            return dp[i][j]=min({t1,t2,t3});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return f(n-1,m-1, word1,word2,dp);
    }
};