class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int n= col.size(), ans=0;
        int i=0;
        while(i<n){
            vector<int> l;
            l.push_back(0);
            while(i<n and col[i]==col[i+1]){
                l.push_back(time[i]);
                i++;
            }
            l.push_back(time[i]);
            
            // cout<<"cycle i"<<" ";
            // for(auto i: l) cout<<i<<" ";
            // cout<<"end cycle"<<endl;
            
            sort(l.begin(), l.end());
            for(int i=0;i<l.size()-1;i++){
                ans+= l[i];
                // cout<<"this is added "<<l[i]<<" ";
            }
            i++;
        }
        return ans;
    }
};