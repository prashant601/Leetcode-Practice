class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        std::array<int, 26> countpat={0};
	    std::array<int, 26> counttxt={0};
	    int pn=pat.length();
	    for(int i=0;i<pn;i++){
	        countpat[pat[i]-'a']++;
	    }
        vector<int> ans;
	    int i=0,j=0;
	    while(j<txt.length()){
	        counttxt[txt[j]-'a']++;
	        if(j-i+1< pn) j++;
	        else if(j-i+1 == pn){
	            if(countpat==counttxt) ans.push_back(i);
	            counttxt[txt[i]-'a']--;
	            j++; i++;
	        }
	    }
	   return ans; 
    }
};