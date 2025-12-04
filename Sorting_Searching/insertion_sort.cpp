#include <iostream>
using namespace std;

void insertionSort(int arr[],int n){
  
   for(int i=1;i<n;i++){
     
    int curr=arr[i];
    int prev=i-1;

   while(prev>=0 && arr[prev]>curr){
       
      arr[prev+1]=arr[prev];
      prev--;
    }
   arr[prev+1]=curr;
  }
}


int main() {
    int arr[5];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i]; 
    }

    insertionSort(arr, 5);

    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
