// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int ans=1;
        vector<int> lis(n,1);
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(a[j]>a[i] && lis[j]<=lis[i])
                    lis[j]=lis[i]+1;
           }
       }
        for(auto i: lis)
            ans=max(ans,i);
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends