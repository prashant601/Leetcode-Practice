class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int A=rowIndex+1;
        if (A == 0) return {};
        vector<vector<int>> r(A);
        r[0].push_back(1);
        for (int i = 1; i < A; ++i) {
            r[i].push_back(1);
            for (int j = 1; j < i; ++j) {
                r[i].push_back(r[i-1][j] + r[i-1][j-1]);
            }
            r[i].push_back(1);
        }
        
        return r.back();   
    }
};