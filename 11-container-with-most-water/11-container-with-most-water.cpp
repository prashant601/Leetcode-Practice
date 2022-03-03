class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int ans=INT_MIN,l=0,r=n;
        while(l<r){
            ans=max(ans, (min(height[l],height[r])*(r-l)) ) ;
            if(height[l]<=height[r])
                l++;
            else 
                r--;
            
        }
        return ans;
            
    }
};