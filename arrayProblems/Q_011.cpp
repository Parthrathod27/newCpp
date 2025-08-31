/*<<<<<Subarray Sum equals to K >>>>>*/


/*brute approch:- 1]we will use 2 pointer approch in which we will use two loop i and j where i will start from 0 index and j will  start from i
                  2]here we will first store all the elements in the int n and then we will create count with value zero
                  3]starting loop i from zero to end of arr in that loop we are crating a sum =0
                    creating another j loop in it which will start from i till end in it we will first add the sum and will  create a condition 
                    where if(sum==k)count++;
                  4]at last it will return the count*/




code:-   

int subarray(vector<int>&arr,int k){

int n=arr.size();
int count=0;

for(int i=0;i<n;i++){
  int sum=0;
   for(int j=i;j<n;j++){
      sum +=arr[j];
      if(sum==k)count++;
    }
  }
 return count;
}





/*optimize approch:-1]we will use prefixsum + hashing approch where first we will create a vector of ps(prefixsum)
                      and its size will be same as the give array we will use a single loop for storing the sum of all element in ps by the formula 
                      ps[i]=ps[i-1]+arr[i] which will store all the sum in ps and will start the loop from i=1 to avoid facing runtime error
                    2]the second part will be use of unordered map in which first we will create the unordered map (m) and then we will itterate 
                      the entire ps by a for loop [j] which will st from 0 till end in which we will create condition
                    3]first condition : if(ps[j]==k)count++;
                      second condition: we will create a val variable in which we will store the ps[j]-k
                                       if(m.find(val)!=m.end()){
                                            count +=m[val]
                      third condition: if the element is present in the ps
                                       m[ps[j]]++;
                    4]we will return the count to get the number of subarray present*/




code:-

int subarray(vector<int>&arr,int k){

int n=arr.size()
int count=0;

vector<int>ps(n,0):
for(int i=1;i<n;i++){
  ps[i]=ps[i-1]+arr[i]
}


unordered_map<int,int>m;
for(int j=0;j<n;j++){
   if(ps[j]==k)count++;

   int val=ps[j]-k;
   if(m.find(val)!=m.end()){
     count=m[val];
   }

  m[ps[j]]++;

}
return 0;

}




                                       




   
