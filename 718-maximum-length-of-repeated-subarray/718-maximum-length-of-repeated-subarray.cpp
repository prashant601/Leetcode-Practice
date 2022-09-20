class Solution {
public:
    
//     int f(int x, int y, vector<int> &nums1, vector<int> &nums2, int count){
//         if(x==0 or y==0) return count;
                
//         if(nums1[x-1]==nums2[y-1])
//             count= f(x-1,y-1, nums1,nums2,count+1);
        
//         int c1= f(x-1,y,nums1, nums2,0);  //substring breaks, count becomes 0
//         int c2= f(x,y-1,nums1, nums2,0);
        
//         return max({count,c1,c2});
//     }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // int n=nums1.size(), m= nums2.size();
        // int count=0;
        // return f(n,m,nums1, nums2,count);
        
        int x=nums1.size();
        int y=nums2.size();
        
        int dp[x+1][y+1];
        // memset(dp,-1,siz)
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++)
                dp[i][j]=0;
        }
        int mx=INT_MIN;
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++)
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                    mx=max(mx,dp[i][j]); 
                }
                else
                    dp[i][j]=0;
        }
        if(mx==INT_MIN)
            return 0;
        return mx;
    }
};