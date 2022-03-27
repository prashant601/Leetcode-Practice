class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        if (row== 0 || col==0) return false;
        
        int low=0,high=row*col;
        while(low<high){
            int mid=low+(high-low)/2;
            int mid_val=matrix[mid/col][mid%col];
            
            if(mid_val==target) return true;
            else if(mid_val>target)  high=mid;
            else low=mid+1;
        }
        return false;
    }
};