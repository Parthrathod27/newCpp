/*<<<<<missing element in the array>>>>>*/


optimize approch:- we will get the sum of array by using formula sum=n*n(n+1)/2
                   and then we will find the acctual sum of the array
                   then just return the sum-arrsum to get the missig element 




code:-


     int n=arr.size();
     int sum=n*(n+1)/2;
     int sumArr=0;
     for(int i=0;i<n;i++){
       sumArr += i;
      }
     return (sum-sumArr);
  };
