class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        vector<int> deg(n,0); // degree array
        vector<vector<int>> direct(n,vector<int> (n,0)); //adjacency matrix
        
        for(auto i: roads){
            deg[i[0]]++;
            deg[i[1]]++;  // degree calculated
            
            direct[i[0]][i[1]]=1;
            direct[i[1]][i[0]]=1;  // matrix filled
        }
        
        
        for(int i=0;i<n;i++){   // calculating the pair with max sum in count array
            for(int j=i+1;j<n;j++){
                ans=max(ans, deg[i]+deg[j]- direct[i][j]); // for directly connected edge, direct[i][j] is used
            }
        }
        return ans;
    }
};