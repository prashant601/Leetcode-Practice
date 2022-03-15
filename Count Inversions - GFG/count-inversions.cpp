// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
 long long merge(long long *arr, long long *temp, long long l, long long mid, long long r){
      long long i,j,k;
      long long inv_cnt = 0;
      
      i = l,j = mid,k = l;
      
      while((i <= mid - 1) && (j<=r)){
          if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];}
          else{
              temp[k++] = arr[j++];
              
              inv_cnt += (mid - i);
          }
      }
      
      while(i<=mid-1){
        temp[k++] = arr[i++];}
        
      while(j<=r){
        temp[k++] = arr[j++];}
    
        for(int i = l; i<=r;i++){
            arr[i] = temp[i];}
        
        return inv_cnt;
      
  }
  long long mergesort(long long arr[], long long tmp[], long long left, long long right){
      long long inv=0, mid=0;
      if(left<right){
          mid=(left+right)/2;
          inv+=mergesort(arr,tmp, left, mid);
          inv+=mergesort(arr,tmp, mid+1,right);
          inv+=merge(arr, tmp, left, mid+1, right);
      }
      return inv;
  }
    long long int inversionCount(long long arr[], long long N)
    {
        long long tmp[N];
        
        return mergesort(arr, tmp, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends