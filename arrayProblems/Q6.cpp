/*<<<<< Left rotate by one place >>>>>*/



code:-

int temp=arr[0];
for(int i=1;i<arr.size();i++){
  arr[i-1]=arr[i];
 }
 arr[n-1]=temp;
 return arr;
}
