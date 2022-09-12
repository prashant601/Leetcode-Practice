class Solution {
public:
    int bagOfTokensScore(vector<int>& tk, int p) {
        sort(tk.begin(), tk.end());
        
        if(tk.size()==0 or p< tk[0]) return 0;
        
        int l=0, n= tk.size(), r=n-1,sc=0,ans=0;
        while(l<=r){
            if(tk[l]<=p){
                p-=tk[l];
                l++,sc++;
            }
            else{
               if(sc==0) return ans;
                p+=tk[r];
                sc--,r--;
            }
            ans=max(ans,sc);
        }
        return ans;
    }
};