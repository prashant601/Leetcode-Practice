class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m= mat[0].size();
        vector<int> ans;
        int flag=0;
        for(int k=0;k<n;k++){ // for row 0 to last
            vector<int> v;
            int i=k,j=0; //i row, j col
            
            while(i>=0 and j<m){
                if(flag%2==1) v.push_back(mat[i][j]);
                else ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(flag%2==1){
                // cout<<"in"<<endl;
                reverse(v.begin(),v.end());
                for(auto i:v) 
                     ans.push_back(i);
            }
            flag++;

        }
        for(int k=1;k<m;k++){ //for col 1 to last
            vector<int> v;
            int i=n-1,j=k; //i row, j col
            while(j<m and i>=0){
                if(flag%2==1) v.push_back(mat[i][j]);
                else ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(flag%2==1){
                // cout<<"in"<<endl;
                reverse(v.begin(),v.end());
                for(auto i:v) 
                     ans.push_back(i);
            }
            flag++;
        }
        return ans;
    }
};