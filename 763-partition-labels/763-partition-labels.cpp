class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]-'a']=i;
        }
        
        
        int mx=INT_MIN,pre=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mx=max(mx,mp[s[i]-'a']);
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