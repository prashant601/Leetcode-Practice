class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int n= heights.size(), gmax=0;
        // for(int i=0;i<n;i++){
        //     int mini=1e9, maxi=0, ar=0;
        //     for(int j=i;j>=0;j--){
        //         mini= min(heights[j],mini);
        //         maxi=max(maxi,(i-j+1)*mini);
        //     }
        //     gmax=max(gmax,maxi);
        // }
        // return gmax;    //brute force
        
        int n=heights.size();
        vector<int> left(n,0), right(n,0);  // for knowing the left and right boundary of every element 
        left[0]=-1, right[n-1]=n;
        
        for(int i=1;i<n;i++){
            int prev=i-1;
            while(prev>=0 and heights[prev]>=heights[i]){  
                prev= left[prev];
            }
            left[i]=prev;
        }
        
        for(int i=n-2;i>=0;i--){
            int prev=i+1;
            while(prev<n and heights[prev]>=heights[i]){
                prev= right[prev];
            }
            right[i]=prev;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int width= right[i]-left[i]-1;
            ans=max(ans, width*heights[i]);
            }
        return ans;
    }
};