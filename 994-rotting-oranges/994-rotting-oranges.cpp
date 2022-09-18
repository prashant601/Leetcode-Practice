class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m= grid.size(), n=grid[0].size(), tot=0, cnt=0, time=0;   //tot stores total oranges(0,2)  ,  cnt is used to return -1,  
        
        queue<pair<int,int>> rottenQ; // bfs is used here
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) rottenQ.push({i,j}); 
            }
        }
        
        int dx[4]={0,0,1,-1};   // for moving to adjacent oranges R L D U
        int dy[4]={1,-1,0,0};
        
        while(!rottenQ.empty()){
            int k=rottenQ.size();
            cnt+=k;
            while(k--){    // taking that k elements from queue. 
                int x= rottenQ.front().first, y= rottenQ.front().second;
                rottenQ.pop();
                
                for(int i=0;i<4;i++){
                    int nx= x+dx[i], ny= y+dy[i];
                    if(nx<0 or ny<0 or nx>=m or ny>= n or grid[nx][ny]!=1) continue;  //if it is boundary element or not a fresh orange 
                    grid[nx][ny]=2;  // marking that orange rotten
                    rottenQ.push({nx,ny});
                }
            }
            if(!rottenQ.empty()) time++;  // increasing the time ,as if cell is inserted in queue (as someone is marked rotten) and q is not empty
        }
        
        return cnt == tot ? time : -1; //if tot == cnt(i.e no. of elements pushed in rottenQ) thus , ans will be the time, else -1.
    }
};