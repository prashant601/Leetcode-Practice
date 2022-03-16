class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        
        int i=0,j=0,mx=0;
        set<char> mp;
        
        while(j<s.size()){
            if(mp.count(s[j])==0){
                mp.insert(s[j]);
                mx=max(mx,(int)mp.size());
                j++;
            }
            else{
                mp.erase(s[i]);
                i++;
            }
        }
        
        return mx;
    }
};