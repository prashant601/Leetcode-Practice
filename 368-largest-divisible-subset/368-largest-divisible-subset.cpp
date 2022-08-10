class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {// same as printing LIS
        int n=arr.size();
        sort(arr.begin(),arr.end()); // in a,b,c if b is divisible a,c is divisible by the c is already divisible by a
        
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        for(int i=0; i<=n-1; i++){

            hash[i] = i; // initializing with current index
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){

                if( arr[i]%arr[prev_index]==0  and  1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }

        int ans = -1;
        int lastIndex =-1;

        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }

        return temp;
    }
};