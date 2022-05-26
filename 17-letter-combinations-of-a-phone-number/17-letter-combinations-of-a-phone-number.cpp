class Solution {
public:
    // We can also use dfs here
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits=="") return ans;
        ans.push_back("");
        vector<string> mapping(10,"");
        mapping[0]="", mapping[1]="",mapping[2]="abc",mapping[3]="def",mapping[4]="ghi",mapping[5]="jkl";
        mapping[6]="mno", mapping[7]="pqrs",mapping[8]="tuv",mapping[9]="wxyz";
        
        vector<string> temp;
        for(int i=0;i<digits.size();i++){
            temp.clear();
            for(auto it: mapping[digits[i]-'0']){
                for(auto itr: ans)
                    temp.push_back(itr+it);
            }
            swap(ans,temp);
        }    
        return ans;
    }
};