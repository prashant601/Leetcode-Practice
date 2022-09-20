class Solution {
public:
    int countPrimes(int n) {
        //seive of eratosthenesis
        vector<int> prime(n+1,1);  //setting all no. to prime
        // prime[1]=0;
        int ans=0;
        for(long long int i=2;i<n;i++){
            
            if(prime[i]==1){
                ans++;  //counting primes
                long long int j=i*i;
                for(;j<n;j=j+i){    // marking all no.s non prime, having factor i
                    prime[j]=0;
                }
            }
        }
        return ans;
    }
};