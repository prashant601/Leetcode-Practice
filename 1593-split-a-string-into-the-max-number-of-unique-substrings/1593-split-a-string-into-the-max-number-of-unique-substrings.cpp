class Solution {
public:
    int ans=0;
    unordered_map<string,int> mp;
    void solve(string &s,int ind,string temp, int res){
        if(ind>= s.size()){
            ans= max(ans, res);
            return;
        }
        
        temp+=s[ind];
        if(mp[temp]==0){
            res++;
            mp[temp]++;
            solve(s, ind+1, "", res);
            mp[temp]--;
            res--;
            
        }
        solve(s, ind+1, temp, res);
    }
    
    int maxUniqueSplit(string s) {
        solve(s,0,"",0);
        return ans;
    }
};