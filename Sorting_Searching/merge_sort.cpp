#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int st,int mid,int end){
     
     vector<int>temp;
     int i=st,j=mid+1;
     while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
          temp.push_back(arr[i]);
          i++;
        }
        else{
          temp.push_back(arr[j]);
          j++;
        }
      }
   
     while(i<=mid){
        temp.push_back(arr[i]);
        i++;
      }
     while(j<=end){
        temp.push_back(arr[j]);
        j++;
      }

    for(int idx=0;idx<temp.size();idx++){
       arr[st+idx]=temp[idx];
     }
} 
     

void mergeSort(vector<int> &arr,int st,int end){
   
      if(st<end){
          int mid=st+(end-st)/2;
         
          mergeSort(arr,st,mid);
          mergeSort(arr,mid+1,end);
          merge(arr,st,mid,end);
       }
}



int main(){
   vector<int> arr(10);
   cout<<"enter the number of list you want to sort"<<endl;
   for(int i=0;i<10;i++){
      cin>>arr[i];
   }
   mergeSort(arr,0,arr.size()-1);
   for(auto val : arr){
     cout<<val<<" ";
   }
   cout<<endl;
  return 0;
} 
