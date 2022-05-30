class Solution {
public:
    void mark_this_island(int x,int y, int m, int n, vector<vector<char>> &grid){
        if(x<0 or y<0 or x>=m or y>=n or grid[x][y]!='1' ) return;
        grid[x][y]='0';
        
        mark_this_island(x,y+1,m,n,grid); //right
        mark_this_island(x,y-1,m,n,grid); //left
        mark_this_island(x+1,y,m,n,grid); //down
        mark_this_island(x-1,y,m,n,grid); // up
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        int m=grid.size(), n=grid[0].size(), cnt=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    mark_this_island(i,j,m,n,grid);
                    cnt++;
                }
            }   
        }
        
        return cnt;
    }
};