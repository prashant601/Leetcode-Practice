class Solution {
public:
    string getSmallestString(int n, int k) {
        int find;
        string ans(n,'a');
        k=k-n;
        while( k != 0){
            find = min(k,25);
            ans[n-1] += find;
            k = k - find;
            n--;
        }
        return ans;
    }
    
};