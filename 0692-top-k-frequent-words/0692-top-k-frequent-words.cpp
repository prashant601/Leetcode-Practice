class Solution {
private:
   static bool cmp(pair<int,string> &a, pair<int,string> &b){
        if(a.first>b.first) return true;
        else if(a.first==b.first) return a.second<b.second;
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        vector<pair<int, string>> temp;
        vector<string> ans;
        for(auto i: words){
            mp[i]++;
        }
        for(auto i: mp)
            temp.push_back({i.second,i.first});
        
        sort(temp.begin(),temp.end(),cmp);
        
        int n=temp.size();
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};