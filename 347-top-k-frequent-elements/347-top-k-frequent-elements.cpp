class Solution {
public:
    static bool sortbysec(const pair<int,int> &aa, const pair<int,int> &b){
        return (aa.second < b.second);
    }
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> mp;
       
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        vector<pair<int,int>> v;
       for(auto i: mp){
           v.push_back(i);
       }
        vector<int> ans;
        sort(v.begin(),v.end(),sortbysec);
        
        for(auto i: v){
            cout<<i.first<<"  "<<i.second<<"  "; 
        }
        if(v.size()==1) return {a[0]};
        for(int i=v.size()-1;i>=v.size()-k && i>=0;i--){
            ans.push_back(v[i].first);
        }
        return ans;
        
    }
};