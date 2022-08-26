class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>&bd,int ind, string &w){
        if(ind==w.size()) return true;
        if(i<0 or j<0 or i>=bd.size() or j>=bd[0].size()) return false;
        if(w[ind]!=bd[i][j]) return false;
        
        char temp=bd[i][j];
        bd[i][j]='*';  //using this as visited array
        
        if( solve(i+1,j,bd,ind+1,w) or solve(i-1,j,bd,ind+1,w) or solve(i,j+1,bd,ind+1,w) or solve(i,j-1,bd,ind+1,w) )
            return true;
        
        bd[i][j]=temp; //backtrack
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and solve(i,j,board,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};