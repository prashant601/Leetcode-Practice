class Solution {
public:
    string getSmallestString(int n, int k) {
        int req=k,sum=0;
        string s="";
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                s.push_back('a'+(req-1));
                break;
            }
            for(int j=1;j<=26;j++)
            {
                int x=(n-i-1)*26;
              
                if(req-j<=x)
                {
                    req=req-j;
                    s.push_back('a'+(j-1));
                    break;
                }
            }
        }
        return s;
    }
    
};