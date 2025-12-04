#include <iostream>
#include <vector>
using namespace std;




int partation(vector<int> &arr,int st,int end){
     int idx=st-1,piv=end;
     for(int j=st;j<=end-1;j++){
        if(arr[j]<=arr[piv]){
          idx++;
          swap(arr[j],arr[idx]);
        }
     }
    idx++;
    swap(arr[idx],arr[piv]);
    return idx;
}
     


void quickSort(vector<int> &arr,int st,int end){
    
    if(st<end){
      int piv=partation(arr,st,end);
      quickSort(arr,st,piv-1);
      quickSort(arr,piv+1,end);
    }
}
     
int main(){
   vector<int> arr(10);
   cout<<"Enter 10 random numbers for sorting"<<endl;
   for(int i=0;i<arr.size();i++){
     cin>>arr[i];
   }
   
   quickSort(arr,0,arr.size()-1);
   for(auto val : arr){
      cout<<val<<" ";
   }
   cout<<endl;
   return 0;
}
