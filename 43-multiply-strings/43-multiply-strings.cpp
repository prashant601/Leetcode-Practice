#include<bits/stdc++.h>
class Solution {
public:
    string sumResults(vector<vector<int>>& results) {
        // Initialize answer as a number from results.
        vector<int> answer = results.back();
        vector<int> newAnswer;
        results.pop_back();
        
        // Sum each digit from answer and result
        for (vector<int> result : results) {
            newAnswer.clear();
            int carry = 0;
            
            for (int i = 0; i < answer.size() || i < result.size(); ++i) {
                // If answer is shorter than result or vice versa, use 0 as the current digit.
                int digit1 = i < result.size() ? result[i] : 0;
                int digit2 = i < answer.size() ? answer[i] : 0;
                // Add current digits of both numbers.
                int sum = digit1 + digit2 + carry;
                // Set carry equal to the tens place digit of sum.
                carry = sum / 10;
                // Append the ones place digit of sum to answer.
                newAnswer.push_back(sum % 10);
            }

            if (carry) {
                newAnswer.push_back(carry);
            }
            answer = newAnswer;
        }
        
        // Convert answer to a string.
        string finalAnswer;
        for (int digit : answer) {
            finalAnswer.push_back(digit + '0');
        }
        return finalAnswer;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0") return "0";
        
        vector<vector<int>> ans;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<num1.size();i++){
            vector<int> v;
            int a=num1[i]-'0', carr=0;
            
            for(int k=0;k<i;k++)  v.push_back(0);
            
            for(int j=0;j<num2.size();j++){
                int b=num2[j]-'0';
                int x=a*b + carr;
                carr=x/10;
                v.push_back(x%10);
            }
            if(carr!=0) v.push_back(carr);
            ans.push_back(v);
        }
        
        string res=sumResults(ans);
        reverse(res.begin(),res.end());
        return res;
    }
};