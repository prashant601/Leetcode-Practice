class Solution {
public:
    bool  check(string &a, string &b){
        if(a.size()!=b.size()+1) return false;
        int f=0,s=0;
        while(f<a.size()){
            if(a[f]==b[s]) f++,s++;
            else f++;
        }
        if(f==a.size() and s==b.size()) return true;
        else return false;
    }
    
    static bool comp(string &s1,string &s2){ 
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& nums) { // nums is word array
        
        sort(nums.begin(),nums.end(),comp);
        
        //Algorithmic approach LIS
        int n=nums.size();
        vector<int> dp(n,1);
        int mx=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){  //  check all previous values before i
                if(check(nums[i],nums[j]))
                    dp[i]=max(dp[i], 1+dp[j]);
            }
            mx=max(mx,dp[i]); // max val in dp array will be the ans
        }
        
        return mx;
    }
};