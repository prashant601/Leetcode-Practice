class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int> arr(n+1);
        arr[0]=0,arr[1]=1;
        int maxi=1;
        for(int i=1;i<=(n-1)/2; i++){
            arr[2*i]= arr[i];
            arr[2*i+1]= arr[i]+arr[i+1];
            maxi=max({maxi,arr[2*i], arr[2*i+1]});
        }
        return maxi;
    }
};