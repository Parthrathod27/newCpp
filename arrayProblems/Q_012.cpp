/*<<<<<Continous Subarray sum>>>>>*/



//Question:Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

/*A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.*/


/*approch:- we will use prifix_sum +unordered map to solve the question in linear time complixity
            first we will create a unordered list of name m 
            then we will create variable of name ps(prifixsum)to store the sum in the variable
            using for loop i which will start from 0 to size of array in that for loop we will add all the elemnts together and save that in ps
            now we will create a rem(remender) variable in which we will first check if the gven k is zero or not , 
            if it is not zero we will calculate the multiple if k by using formula [sum%k=0] and put that value in rem
            if it is zero we will put rem=ps
            now we will fetch the unordered map in which first we will check if rem is present or not if it is present 
            we will check the size of that rem because the condition is already given that the subarray should be greater than or equal to 2
            if it satisfy the given contdition return true
            else store the i in the rem
            at last return false ( if the condition is not satisfy the return value will be false)*/


code:-


bool checkArray(vector<int>arr,int k){

int n=arr.size();
unordered_map<int,int>m;
m[0]=-1;

int ps=0;
for(int i=0;i<n;i++){
 ps+=arr[i];

 int rem;
 if(k!=0){
   rem=ps%k;
 }
 else{
   rem=ps;
 }


 if(m.find(rem)!=m.end()){
  if(i-m[rem]>=2){
     return true;
  }
 } 

 else{
  m[rem]=i;
 }
}
return false;

}
