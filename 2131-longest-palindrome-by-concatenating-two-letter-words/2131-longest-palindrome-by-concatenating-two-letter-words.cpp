class Solution {
public:
    bool pal(string &s){
        int l= 0, r= s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        int c=0, mn=0;
        map<string, int> mp;
        for(auto &i: words){
            mp[i]++;
        }
        
        for(auto &i: words){
            if(pal(i) and mp[i]>0 and mp[i]%2!=0) {
                c+= 2 ; // counting length of all palindromes 
                mp[i]-=1;
                break;
            }
        }
        
        for(int i=0;i<words.size();i++){
            
                string rev= words[i];
                reverse(rev.begin(), rev.end());
                if(rev==words[i]) {
                    c+= (mp[words[i]]/ 2 )*2*2;
                    mp[words[i]]=0;
                }
                else if(mp.find(rev)!=mp.end()){
                    c+=min(mp[rev], mp[words[i]]) * rev.size()*2;
                    mp[rev]=0;
                    mp[words[i]]=0;
                }
            
        }
        
        return c;
    }
};