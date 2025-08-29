/*<<<<<move all zero in the last of array>>>>>*/


approch:-we will use two pointer approch
         we will find the zero's index
         start the loop from -1 and name that loop as j
         start another pointer as i=j+1 hence we will put a condition where if arr[i]!=0
         swap the element arr[j],arr[i] hence at the end of the itteration all zeros will be at the end of the array




code:-
  

 vector<int> movezeros(vector<int>&arr,int n){

int j=-1
for(int i=0;i<n;i++){
  if(arr[i]==0){
    j=i;
    break;
   }
 }

if(j==-1)return 0;//no such zeros

for(int i=j+1;i<n;i++){
 if(arr[i]!=0){
  swap(arr[i],arr[j]);
  j++;
  }
 }
return 0;
}
