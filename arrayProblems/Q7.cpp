/*<<<<< Left rotate array by D place >>>>>*/

/*approch:-here we have given d as the imput
           so just divide te arr to the number given 
           example-arr[1,2,3,4,5,6] d=2
                 dividing-arr[1,2][3,4,5,6]
           then reverse both the part
             reverse-arr[2,1][6,5,4,3]
           then combine both part and reverse the whole array
           output-arr[3,4,5,6,2,1]



code-
     vector<int> reverse(vector<int>&arr,int start,int end){
       while(start<=end){
         int temp=arr[start];
         arr[start]=arr[end];
         arr[end]=temp;
         start++;
         end--;
       }
    }
   

   vector<int> reverseArr(vector<int>&arr,int d,int n){
     reverse(arr,arr+d)
     reverse(arr+d,arr+n)
     reverse(arr,arr+n)
  }   
