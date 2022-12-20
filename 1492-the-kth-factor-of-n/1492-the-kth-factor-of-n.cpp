class Solution {
public:
    int kthFactor(int n, int k) {
        int i=1,cnt=0;
        while(i<=n){
            // cout<<"inside "<<i<<" ";
            if(n%i==0) cnt++;
            if(cnt==k) return i;
            i++;
        }
        // cout<<n<<" "<<k<<endl;
        return -1;
    }
};