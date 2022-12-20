class Solution {
public:
    int nextGreaterElement(int n) {
//         int nbit= (int)log2(n)+1;
//         // cout<<nbit<<endl;
//         if(nbit>32) return -1;
//         int d=0,k=n;
//         vector<int> v;
//         while(k>0){
//             d=k%10;
//             v.push_back(d);
//             k=k/10;
//         }
//         reverse(v.begin(),v.end());
//         unsigned int ans=0;
//         if(!next_permutation(v.begin(), v.end())) return -1;
        
//         // next_permutation(v.begin(), v.end());
//         for(auto i: v)
//             cout<<i<<"@ ";
//         // cout<<(-2147483648<INT_MIN);
//         for(int i=0;i<v.size();i++){
//             if(ans>=INT_MAX or ans<0) return -1;
//             ans=(ans*10)+v[i];
//             // cout<<ans<<" ";
//         }
//         // cout<<(int)log2(ans)+1 <<endl;
//         if(ans<0 or (int)log2(ans)+1 >=32) return -1;
//         return ans ;
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        string temp = s;
        prev_permutation(temp.begin(),temp.end());
        if(s<=temp) return -1;
        long long ans = stoll(s,nullptr,10);
        return (ans>INT_MAX || ans<INT_MIN)? -1 : ans;
        
    }
};