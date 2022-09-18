class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int c=0;
    int st=0;
    // int st=image[sr][sc];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(c==0)
            st=image[sr][sc];
        
        if(sr<0||sc<0 ||sr>=image.size() || sc>=image[0].size())
            return image;
        
        if(image[sr][sc]!=st)
            return image;
        if(image[sr][sc]==newColor)
            return image;
        
        image[sr][sc]=newColor;
        for(int k=0;k<4;k++){
            c++;
            floodFill(image,sr+dx[k],sc+dy[k],newColor);
        }
        return image;
        }
};