class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string ms[26] ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string m="";
            for(int j=0;j<s.size();j++){
                m+=ms[s[j]-'a'];
            }
            ans.insert(m);
        }
        return ans.size();
    }
};