class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int r1=0,r2=n-1,c1=0,c2=n-1,val=1;
        while(r1<=r2 && c1<=c2){
            for(int i=c1; i<=c2;i++)  // moving right
                ans[r1][i]=val++;
            
            for(int j=r1+1;j<=r2;j++) // moving down
                ans[j][c2]=val++;
            
            if(r1<r2 && c1<c2){
                for(int i=c2-1;i>c1;i--) //moving left to right
                    ans[r2][i]=val++;
                
                for(int j=r2;j>r1;j--) // moving bottom to up
                    ans[j][c1]=val++;
                
            }
            r1++,r2--;
            c1++,c2--;
        }
        return ans;
    }
};