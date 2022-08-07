class Solution {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){ 
        //taking only 1 i as they move in next row together so i will same for both 
    
        if(j1<0 or j2<0 or j1>=c or j2>=c) return -1e8; //out of bound case
        
        if(i==r-1){
            if(j1==j2) return grid[i][j1];    // incase of common landing cell  
            else return grid[i][j1]+ grid[i][j2]; 
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=-1e8;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1; dj2<=+1 ;dj2++){
                int val=0;
                if(j1==j2)
                {
                    val=grid[i][j1]; // for common cell
                }
                else
                {
                  val=grid[i][j1]+grid[i][j2]; // for diff cell
                }
                val+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                maxi=max(maxi,val);
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size(), c= grid[0].size();
        vector<vector<vector<int>>> dp(r+1, vector<vector<int>> (c+1, vector<int>(c+1,-1)));
        return f(0,0,c-1, r, c, grid, dp);
    }
};