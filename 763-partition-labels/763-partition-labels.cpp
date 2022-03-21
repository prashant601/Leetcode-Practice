class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        
        
        int mx=INT_MIN,pre=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mx=max(mx,mp[s[i]]);
            if(mx==i){
                ans.push_back(mx-pre);
                pre=mx;
                mx=INT_MIN;
            }
        }
        ans[0]++;
        return ans;
    }
};