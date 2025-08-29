/*<<<<<union of two array>>>>>*/


/*approch:-creating a arr of vector in which the union will be stored
        creating two different loop for two different array with name i and j which will start from zero till end 
        using while loop for itterating over all the array in that we will make a condition in which 
        if the arr[i]<=arr[j] then push that elemnt to arrunion but in that also we will check if the arrunion has same existing element if
        it is not present then only we will push that element same for the second array
        if one of the array's itteration is completed then it will stop so to overcome we will use same while loop with condition 
        (j<arr.size()),(i<arr.size())*/



code:-   vector<int>union(vector<int>&a,vector<int>&b){

int n1=a.size();
int n2=b.size();
int i=0;
int j=0;
vector<int>arrUnion;
while(i<n1 && j<n2){
  if(a[i]<=b[j]){
    if(arrUnion==0 || arrUnion.back()!=a[i]){
       arrUnion.push_back(a[i]);
    }
   i++;
  }

 else{
    if(a[i]>b[j]){
      if(arrUnion==0 || arrUnion.back!=b[j]){
         arrUnion.push_back(b[j]);
    }
   j++;
  }

while(i<n1){
    if(arrUnion==0 || arrUnion.back()!=a[i]){
       arrUnion.push_back(a[i]);
    }
   i++;
  }


while(j<n2){
     if(a[i]>b[j]){
      if(arrUnion==0 || arrUnion.back!=b[j]){
         arrUnion.push_back(b[j]);
    }
   j++;
  }

return arrUnion;

}
