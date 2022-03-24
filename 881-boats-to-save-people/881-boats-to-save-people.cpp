class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0,r=people.size()-1,c=0,d=0;
        sort(people.begin(),people.end());
        while(l<=r){
            if(l==r)
                c++,r--;
            else if(people[l]+people[r]<=limit){
                c++,l++,r--;
            }
            else if(people[l]+people[r]>limit){
                c++,r--;
            }
        }
        return c;
    }
};