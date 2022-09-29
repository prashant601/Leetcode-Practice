class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0, a=arr[0], mn= INT_MAX;
        for(i=0;i<arr.size();i++){
            if(abs(arr[i]-x)<mn){
                mn= abs(arr[i]-x);
                a= i;
            }
        }
        vector<int> ans;
        // cout<<a<<endl;
        int l= a, r= a;
        
        if(a+1< arr.size()) r= a+1;
        else if(a-1>=0) l=a-1;
        
        // cout<<l<<" "<<r<<endl;
        while((l>=0 and r< arr.size()) and k>0){
            if(abs(arr[l]-x)<= abs(arr[r]-x))
                ans.push_back(arr[l--]);
            else 
                ans.push_back(arr[r++]);
            k--;
        }
        while(k>0){
            if(l>=0){
                ans.push_back(arr[l--]);
            }
            else if(r<arr.size()){
                ans.push_back(arr[r++]);
            }
            k--;
        }
        // cout<<a<<endl;
        sort(ans.begin(),ans.end());
        return ans;
    }
};