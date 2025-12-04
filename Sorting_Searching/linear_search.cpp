#include <iostream>
using namespace std;

int linearSearch(int arr[],int n,int value){
    for(int i=0;i<n;i++){
       if(arr[i]==value){
          return i;
       }
    }
  return -1;
}

int main(){
   int arr[5];
   int value;

    cout << "Enter 5 numbers: ";
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
       cout<<"the value is on the index :"<<val<<endl;
    }

    return 0;
}
