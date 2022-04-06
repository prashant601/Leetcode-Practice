class Solution {
private:
    string intersect(string &a, string &b){
        string res="";
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i]) res+=a[i];
            else break;    
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            s=intersect(s,strs[i]);
        }
        return s;
    }
};