class Solution {
public:
     static bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) 
    { 
        return (a.second < b.second); 
    } 
    int getKth(int lo, int hi, int K) {
        int k=0, ind=0;
        vector<int> a(hi-lo+1,0);
        for(int i=lo;i<=hi;i++){
            k=0;
            int temp=i;
            while(temp!=1){
                if(temp%2==0)
                    temp=temp/2;
                else 
                    temp=3*temp+1;
                k++;
            }
            a[ind]=k;
            ind++;
        }
        
        vector<pair<int,int>> vec;
        
        for(int i=lo;i<=hi;i++){
            vec.push_back({a[i-lo],i});  //creating a pair with first as value as power(i.e. k) and second as no.
        }
        
        sort(vec.begin(), vec.end()); 
 
        return vec[K-1].second;
    }
};