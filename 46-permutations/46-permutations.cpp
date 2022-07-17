class Solution {
public:
    void solve(vector<int> v, vector<int> &nums, vector<vector<int>>& ans, vector<bool> &freq){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==false){
                freq[i]=true;
                v.push_back(nums[i]);
                solve(v,nums,ans,freq);
                freq[i]=false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        vector<bool> freq(n);
        for(int i=0;i<n;i++){
            freq[i]=false;
        }
        solve(v,nums,ans,freq);
        return ans;
    }
};