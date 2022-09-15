class Solution {
public:
    static bool cmp(int &a, int &b){
        return abs(a)< abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        int n= arr.size();
        vector<int> ans;
        
        sort(arr.begin(),arr.end(),cmp);
        
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        // for(auto i: arr) cout<<i<<" ";
        
        for(int i=0; i<n;i++){
            if(mp[arr[i]]==0) continue;

            int k= 2*arr[i];
            if(mp[k]==0) return false;
            ans.push_back(arr[i]);
            mp[arr[i]]--;
            mp[k]--;
            
        }
        
        
        if(ans.size()==0) return false;
        return true;
    }
};