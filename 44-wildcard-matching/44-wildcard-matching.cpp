class Solution {
public:
//     int f(int i, int j, string p, string s, vector<vector<int>>&dp){
//         if(i<0 and j<0) return true; //both needs to be exhausted to matches completely
//         if(i<0 and j>=0) return false; // we can remove j>=0 as above cond. is already taking care of that
        
//         if(i>=0 and j<0){ // need to be all * otherwise false
//             for(int it=0;it<=i;it++) if(p[it]!='*') return false;
//             return true;
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(p[i]==s[j] or p[i]=='?') return dp[i][j]= f(i-1,j-1,p,s,dp); 
//         if(p[i]=='*') return dp[i][j]= ( f(i-1,j,p,s,dp) or f(i,j-1,p,s,dp) );   
//                             // match for *      // leave * i.e * as empty string
//         else return dp[i][j]= false;
//     }
    bool isMatch(string s, string p) {
        // int n=p.size(), m= s.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n-1,m-1,p,s,dp);
        
        //tabular
        int n=p.size(), m= s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0]=true; // for -ve i,j shifting of index
        for(int i=1;i<=n;i++){   //3rd base cond
            bool flag=true;
            for(int it=1;it<=i;it++){
                if(p[it-1]!='*') {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                dp[i][0]=true;
        }                                        // initialisation done
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] or p[i-1]=='?') dp[i][j]= dp[i-1][j-1];
                else if(p[i-1]=='*') dp[i][j]= dp[i-1][j] or dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};