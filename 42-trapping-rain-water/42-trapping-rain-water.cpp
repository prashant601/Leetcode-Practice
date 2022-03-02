class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,ans=0;
        int lmax=INT_MIN,rmax=INT_MIN;
        while(l<r){
            if(height[l]<height[r]){
                lmax=max(lmax,height[l]);
                ans+=(lmax-height[l]);
                l++;
            }
            else {
                rmax=max(rmax,height[r]);
                ans+=(rmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};  