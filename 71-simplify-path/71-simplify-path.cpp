class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        string temp,res;
        stringstream ss(path);
         while(getline(ss,temp,'/')) {
             if(temp=="." || temp=="") continue;
             if(temp==".." && !ans.empty()) ans.pop_back();
             else if( temp!="..") ans.push_back(temp);
         }
        for(auto i: ans){
            res+= "/"+i;
        }
        if(res.empty()) return "/";
        return res;
        
        
        // string ans;
        // int c=0,n=path.size();
        // for(int i=0;i<n;i++){
        //     if(path[i]=='.')
        //         continue;
        //     else if(path[i]=='/' && c==0 && i!=n-1){
        //         ans+=path[i],c++;
        //         // cout<<"path "<<i<<endl;
        //     }
        //     else if(path[i]!='/')
        //         ans+=path[i],c=0;
        // }
        // if(ans.size()>=2)
        // if(ans[ans.size()-1]=='/' && ans[ans.size()-2]!='/') ans=ans.substr(0, ans.length() - 1);
        // return ans;
    }
};