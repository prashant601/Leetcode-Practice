#include<bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        int sl=s.size(), tl=t.size();
        if(tl>sl) return "";
        
        int sf[256]={0};  // frequency array of string characters 
        int tf[256]={0};  
        
        for(int i=0;i<tl;i++){  // filling the freq. array of pattern
            char ch=t[i];
            tf[ch]++;
        }
        
        int cnt=0,wind=INT_MAX,start=0,start_idx=-1;
        for(int i=0;i<sl;i++){
            //pushing the char in string frequency array
            char ch= s[i];
            sf[ch]++;
            
            //maintain the count of characters matched
            if(tf[ch]!=0 and sf[ch]<=tf[ch])
                cnt++;
            
            //if all characters matched
            if(cnt==tl){
                //start shrinking the window
                char temp= s[start];
                while( tf[temp]==0 or sf[temp]>tf[temp] ){
                    sf[temp]--;
                    start++;
                    temp=s[start];
                }
                
                int len=i-start+1; //length of the window
                if(len<wind){    // checking the minimum size of the window ans updating the window info 
                    wind=len;
                    start_idx=start;
                }
            }
        }
        if(start_idx==-1) return "";
        return s.substr(start_idx, wind);
    }
};