class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        
        int i=0,j=0,mx=0;
//         unordered_set<char> mp;
        
//         while(j<s.size()){
//             if(mp.find(s[j])==mp.end()){
//                 mp.insert(s[j]);
//                 mx=max(mx, j-i+1);
//                 j++;
//             }
//             else{
//                 mp.erase(s[i]);
//                 i++;
//             }
//         }
        
        int store[256]={0};
        while(j<s.length())    
        {
            store[s[j]]++;      
            while(store[s[j]]>1)  
            { 
                store[s[i]]--;   
                i++;
            }
            mx = max(mx,j-i+1);    
            j++;
        }
        
        return mx;
    }
};