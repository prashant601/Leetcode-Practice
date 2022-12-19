class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         int n=mat.size(),len=0, t=0, m= mat[0].size();
//         for(auto i: mat){
//             int k= i.size();
//             len+=k;
//             m=max(m,k);
//         }
        
//         vector<int> ans, res(len,0);
//         int flag=0;
//         for(int k=0;k<n;k++){ // for row 0 to last
//             vector<int> v;
//             int i=k,j=0; //i row, j col
            
//             while(i>=0 and j<m){
//                 // if(j>mat[i].size()) continue;
//                 if(j<mat[i].size()){
//                     res[t++]=mat[i][j];
//                     // ans.push_back(mat[i][j]);
//                 }
//                 i--;
//                 j++;
//             }
            

//         }
//         for(int k=1;k<m;k++){ //for col 1 to last
//             vector<int> v;
//             int i=n-1,j=k; //i row, j col
//             while(j<m and i>=0){
//                 // if(j>mat[i].size()) continue;
//                 if(j<mat[i].size()){
//                     res[t++]=mat[i][j];
//                     // ans.push_back(mat[i][j]);
//                 }
//                 i--;
//                 j++;
//             }
//         }
//         return res;
        queue<vector<int>> q;
        q.push({0, 0});
        vector<int> ans;
        while(!q.empty()){
            int row = q.front()[0], col = q.front()[1];
            q.pop();
            ans.push_back(nums[row][col]);
            if(row + 1 < nums.size() && col == 0)q.push({row+1, col});
            if(col + 1 < nums[row].size())q.push({row, col+1});
        }
        return ans;
    }
};