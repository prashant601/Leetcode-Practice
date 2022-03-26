// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
       int n=r,m=c;
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
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends