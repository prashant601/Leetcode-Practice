class Solution {
public:
    vector<vector<int>> generate(int A) {
        vector<vector<int>> ans;
        if(A==0) return ans;
        if(A==1){
            ans.push_back({1});
            return ans;
        }
        if(A>1){
            ans.push_back({1});
            ans.push_back({1,1});
        }
        for(int i=2;i<A;i++){
            vector<int> temp;
            // cout<<ans.back()[0]<<" ";
            // cout<<i<<endl;
            for(int j=0;j<i-1;j++){
                temp.push_back(ans.back()[j]+ans.back()[j+1]);
            }
            temp.insert(temp.begin(),1);
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;   
    }
};