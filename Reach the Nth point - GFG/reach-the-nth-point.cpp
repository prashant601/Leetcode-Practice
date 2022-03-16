// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
    		int fib[n+2];
    		int mod=1000000007;
    		fib[0]=0;
    		fib[1]=1;
    		for(int i=2;i<=n+2;i++){
    		    fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
    		  //  cout<<fib[i]<<" ";
    		}
		    return fib[n+1];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends