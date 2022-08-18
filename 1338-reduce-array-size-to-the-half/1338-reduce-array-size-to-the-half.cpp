class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int ans=0,n=arr.size(), cnt=0;
        
        for(auto i:v){
            if(cnt>=n/2) break;
            cnt+=i.first;
            ans++;
        }
        return ans;
    }
};