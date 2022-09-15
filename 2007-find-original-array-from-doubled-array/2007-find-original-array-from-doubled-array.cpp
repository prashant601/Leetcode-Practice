class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        int n= ch.size();
        vector<int> ans;
        
        if(n%2!=0) return ans;
        
        sort(ch.begin(),ch.end());
        
        
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[ch[i]]++;
        }
    
        for(int i=0; i<n;i++){
            if(mp[ch[i]]<=0) continue;
            
            int k= 2*ch[i];
            if(mp[k]==0) return {};
            ans.push_back(ch[i]);
            mp[ch[i]]--;
            mp[k]--;
        }
        
        return ans;
    }
};