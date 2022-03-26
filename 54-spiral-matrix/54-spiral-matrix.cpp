class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> res;
        int r1=0,r2=n-1,c1=0,c2=m-1,val=1;
        while(r1<=r2 && c1<=c2){
            for(int i=c1; i<=c2;i++)  // moving right
                res.push_back(matrix[r1][i]);
            
            for(int j=r1+1;j<=r2;j++) // moving down
                res.push_back(matrix[j][c2]);
            
            if(r1<r2 && c1<c2){
                for(int i=c2-1;i>c1;i--) //moving left to right
                    res.push_back(matrix[r2][i]);
                
                for(int j=r2;j>r1;j--) // moving bottom to up
                    res.push_back(matrix[j][c1]);
                
            }
            r1++,r2--;
            c1++,c2--;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)
        //         res.push_back(ans[i][j]);
        // }
        return res;
    }
};