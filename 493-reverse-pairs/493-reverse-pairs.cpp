#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //find_by_order, order_of_key
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set<int> s;
        int n=nums.size(), ans=0;
        
        for(int i=n-1;i>=0;i--){
            
            //count nos less than (i+1)/2;
            ll p;
            
            if(nums[i]>0)
             p=((ll)nums[i]+1)/2;
            
            else 
                p=((ll)nums[i])/2;
            
            ll z=s.order_of_key(p);
            ans+=z;
            s.insert(nums[i]);
        }
        
        return ans;
    }
};