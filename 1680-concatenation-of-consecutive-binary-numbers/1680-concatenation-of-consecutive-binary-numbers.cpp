#define ll long long int
class Solution {
public:

    // string to_binary(int n){
    //     string ans="";
    //     while(n>0){
    //        ans+=to_string(n%2);
    //         n=n/2;
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len);
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};