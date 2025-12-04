#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int value){
     int st=0,end=n-1;
    while(st<=end){
     
     int mid=st+(end-st)/2;
     
     if(value==arr[mid]){
       return mid;
     }
     else if(value<arr[mid]){
       end=mid-1;
     }
     else{
       st=mid+1;
     }
   }
  return -1;
}

int main(){
   int arr[5];
   int value;
    
    cout << "Enter 5 numbers in a sorted order : "; 
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    cout<<"enter the value you want to search"<<endl;
    cin>>value;
    
    int val=linearSearch(arr,5,value);
    if(val==-1){
      cout<<"value did not exist"<<endl;
    }
    else{
       cout<<"the value is on the index"<<val<<endl;
    }
    
    return 0;
}

