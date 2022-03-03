class Solution {
public:
     bool safestate(int row, int col, vector<string> &board, int n){
        for(int i=0; i<col;i++){
            if(board[row][i]=='Q')
                return false;
        }
        int row1=row,col1=col;
        row1--;
        col1--;
        while(row1>=0 && col1>=0){
            if(board[row1][col1]=='Q')
                return false;
            row1--;
            col1--;
        }
        while(col>=0 && row<n){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    
    void solve(int col, vector<string> &board, int &ans, int n){
        if(col==n){
            ans++;
            return;
            }
        
        for(int row=0;row<n;row++){
            if(safestate(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        solve(0,board,ans,n);
        return ans;
    }
};