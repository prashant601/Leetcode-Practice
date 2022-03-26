class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1,mid;
        while(l<r){               //finding the first element 
            mid=(l+r)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else
                r=mid;
        }
        
        int start,end;
        if(target>=nums[l] && target<=nums[n-1] ){  //checking whether target is in left part or right part
            start=l;
            end=n-1;
        }
        else{
            start=0;
            end=l-1;
        }
        cout<<l<<" ";
        while(start<=end){    // simply searching the target
            mid=(start+end)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]>target)
                end=mid-1;
            else
                return mid;
        }
        
        return -1;
        
    }
};