class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char, int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<bool> visited(256, false);
        
        for(int i=0;i<n;i++){
            mp[s[i]]--;
            if(visited[s[i]])  continue;
            while(!st.empty()){
                if((int)(s[i]) < (int)(st.top()) && mp[st.top()]>0){
                    // mp[st.top()]--;
                    visited[st.top()] = false;
                    st.pop();
                    }
                else
                    break;
                }
            st.push(s[i]);   
            visited[s[i]] = true;
            }
        set<char> set;
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }    
};