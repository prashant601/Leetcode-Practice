class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact= fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1; //as indexing is 0 based
        string ans="";
        while(true){
            ans=ans+ to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact); //removing the no. from nums array which is added in ans 
            if(nums.size()==0) break;
            k=k%fact;
            fact=fact/nums.size();  //getting fact of 1 less no.
        }
        return ans;
    }
};