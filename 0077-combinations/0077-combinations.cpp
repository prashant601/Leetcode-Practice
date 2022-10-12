class Solution {
public:
    void solve(vector<int> v, vector<vector<int>>& ans,int n , int k){
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(n>k) solve(v, ans, n-1, k);
        v.push_back(n);
        solve(v, ans, n-1, k-1);      
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(v,ans,n,k);
        return ans;
    }
};