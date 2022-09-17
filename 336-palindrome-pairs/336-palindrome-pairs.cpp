class Solution {
public:
    bool palind(string &s){
        int l= 0, r= s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& w) {
        unordered_map<string,int> mp;
        for(int i=0;i<w.size();i++){
            string s= w[i];
            reverse(s.begin(),s.end());
            mp[s]=i;
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<w.size();i++){
            for(int j=0;j<=w[i].size();j++){                          // ex: abcd 
                string pre= w[i].substr(0,j);  // getting prefix            ab
                string suf= w[i].substr(j);    // getting suffix            cd
                
                if(mp.count(pre) and palind(suf) and mp[pre]!=i)   // checking if suf is palindrome then pre must present in mp
                    ans.push_back({i,mp[pre]});
                if(!pre.empty() and mp.count(suf) and palind(pre) and mp[suf]!=i) // same goes for opposite and also check pre is not empty
                    ans.push_back({mp[suf], i});
            }
        }
        return ans;
    }
};