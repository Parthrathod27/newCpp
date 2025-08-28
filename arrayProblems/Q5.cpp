/*<<<<<Find second largest element in the array>>>>>*/



int largest=arr[0];
int slargest=-1;
for(int i=0;i<arr.size(0;i++){
    if(arr[i]>largest){
      slargest=largest;
      largest=arr[i];
      }
    else if(arr[i]<largest && arr[i]>slargest){
      slargest=arr[i];
      }
 }

 if(true){
   return slargest;
  }
 else{
  return -1;
 }
