// class Solution {
// public:
//     bool isPalindrome(int i, int j, string&s){
//         while(i<j){
//             if(s[i]==s[j]){
//                 i++;
//                 j--;
//             }
//             else return false;
//         }
//         return true;
//     }
// //     int mcm(int i, int j, string &s,vector<vector<int>> &dp){
// //      //j will always be n, we can replace j with n, only 1d dp will be required
// //         if(i==j) return 0;
        
// //         if(dp[i][j]!=-1) return dp[i][j];
        
// //         int mini= 1e9;
// //         for(int k=i;k<=j;k++){
// //             if(isPalindrome(i,k,s)){
// //                 int cost= 1+ mcm(k+1,j,s,dp);  //this mcm is for checking right partition palindrome (as left one is )
// //                 mini=min(cost, mini);
// //             }
// //         }
// //         return dp[i][j]=mini;
// //     }
//     int minCut(string s) {
//         // int n=s.size();
//         // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
//         // return mcm(0,n,s,dp) -1 ;  //-1 is for excluding the last partition (eg. in ABC=>  A|BC => A| (B|C) => A| B| C| ) we need to exclude that partition after C
        
//         //tabular
//         int n=s.size();
//         vector<int> dp(n+1,0);
//         dp[n]=0;
//         for(int i=n-1;i>=0;i--){
//             int mini= 1e9;
//             for(int k=i;k<=n;k++){
//                 if(isPalindrome(i,k,s)){
//                     int cost= 1+ dp[k+1];  
//                     mini=min(cost, mini);
//                 }
//             }
//             dp[i]=mini;
//         }
//         return dp[0]-1;
//     }
// };

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
    int mcm(int i, int n, string &s,vector<int> &dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int mini= 1e9;
        for(int k=i;k<=n;k++){
            if(isPalindrome(i,k,s)){
                int cost= 1+ mcm(k+1,n,s,dp);  //this mcm is for checking right partition palindrome (as left one is already a palindrome)
                mini=min(cost, mini);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1, -1);
        return mcm(0,n,s,dp) -1 ;  //-1 is for excluding the last partition (eg. in ABC=>  A|BC => A| (B|C) => A| B| C| ) we need to exclude that partition after C
    }
};