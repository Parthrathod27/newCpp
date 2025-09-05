/*<<<<<Rearrange the array by sign>>>>>*/


/*there are two type in this condition 1]type1:where the no of negative and positive are equal .
                                       2]type2:where the no of hegative and positive is not equal.*/


//1]Type:


/*brute force approch:-Create two extra arrays (or vectors): one for positives, one for negatives.
Traverse the input array once:
If the element is positive, push it into the positive array.
If the element is negative, push it into the negative array.
Since the problem guarantees equal positives and negatives, both arrays will have the same size.
Build the result by alternating elements:
Place positives at even indices (0, 2, 4,...)
Place negatives at odd indices (1, 3, 5,...).*/

//TC:O(2N),SC:(N).


code:

vector<int> arangeArr(vector<int>&nums){
   int n=nums.size();
   vector<int>pos,neg;
   for(int i=0;i<n;i++{
     if(nums[i]>0){
       pos.push_back(nums[i]);
     }
     else{
       neg.push_back(nums[i]);
     }

   vector<int>arr(n);
   for(int i=0;i<n/2;i++){
     arr[2*i]=pos[i];
     arr[2*i+1]=neg[i];
   }

   return arr;
 }
};


/*optimize approch:nstead of using two extra arrays (pos and neg), we can directly rearrange the elements while scanning:
Create a result array of size n (or rearrange in-place if allowed).
Use two indices:
posIndex = 0 (even positions)
negIndex = 1 (odd positions)
Traverse the original array:
If the number is positive → place it at arr[posIndex], then increase posIndex by 2.
If the number is negative → place it at arr[negIndex], then increase negIndex by 2.
By the end, positives are at even indices and negatives at odd indices.*/

//TC:O(N),SC:O(N).

code:

vector<int>arrangeArr(vector<int>&nums){
 int n=nums.size();
 vector<int>arr(n);
 int pos=0,neg=1;
 for(int i=0;i<n;i++){
    if(nums[i]>0){
      arr[pos]=nums[i];
      pos+=2;
    }
    else{
      arr[neg]=nums[i];
      neg+=2;
    }
 }
 return arr;
}
};


//2]Type

/*approch:To handle unequal counts, first scan the array once and split numbers into two lists:
 pos for positives and neg for negatives; this costs O(n).
 Create a result array arr of size n, and decide who starts: if you want the longer group to maximize alternating length,
 start with whichever list is longer (else, fix a start—e.g., positive first—per problem requirement).
 Maintain two write pointers: one for even indices (0, 2, 4, …) and one for odd (1, 3, 5, …).
 While both lists still have elements, place one from the starting list at the current even (or odd) position 
and one from the other list at the opposite position, advancing each position by 2 after every placement, effectively alternating signs.
 Once the smaller list is exhausted, compute the next free index (it will be 2 * min(pos.size(), neg.size()) if you began at 0) 
and append all remaining elements from the longer list sequentially into arr from that index onward (no more alternation possible).
 This produces an array that alternates as long as possible,
 with any surplus of the majority sign neatly tacked on at the end, in O(n) time and O(n) extra space.*/


code:

vector<int>arrangeArr(vector<int>&arr){
 int n=nums.size();
 vector<int>pos,neg;
 for(int i=0;i<n;i++){
   if(nums[i]>0){
     pos.push_back(nums[i]);
   }
   else{
     neg.push_back(nums[i]);
   }

 vector<int>arr(n);
 if(pos.size()>neg.size()){
   for(int i=0;i<neg.size();i++){
      arr[2*i]=pos[i];
      arr[2*i+1]=neg[i];
    }
   int index=0;
   for(int i=neg.size();i<pos.size();i++){
       arr[index]=pos[i];
       index++;
    }
  }
  else{
    for(int i=0;i<pos.size();i++){
      arr[2*i]=pos[i];
      arr[2*i+1]=neg[i];
    }
    int index=0;
    for(int i=pos.size();i<neg.size();i++){
       arr[index]=neg[i];
       index++;
    }
  }
 return arr;
}
};

