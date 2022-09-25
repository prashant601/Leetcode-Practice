class Solution {
public:
    static bool mycmp(string &a, string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
         vector<string> v;
        for(auto i: nums)
            v.push_back(to_string(i));
        
        sort(v.begin(),v.end(), mycmp);
        if(v[0]=="0") return "0";
        
        string ans="";
        for(auto i:v)
            ans+=i;
        return ans;
    }
};