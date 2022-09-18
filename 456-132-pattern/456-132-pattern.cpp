class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n= nums.size(), pre=INT_MIN;
        stack<int> s;
        // using stack sortable permutation
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top()< nums[i] ){
                if(pre>s.top()) return true;
                pre= s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        
        return !s.empty() and pre> s.top();
    }
};