/*<<<<<Power of X,n>>>>>*/


/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

/*This code implements fast exponentiation (binary exponentiation) to compute x^n
 efficiently. It first handles special cases like when the base is 0, 1, or –1, or when the exponent is 0.
 To deal with negative exponents, it takes the reciprocal of 𝑥
x and makes the exponent positive using a long to avoid overflow.
 Then it repeatedly squares the base while halving the exponent: if the current exponent bit is 1 (i.e., binform % 2 == 1),
 it multiplies the answer by the current base; otherwise, it just squares the base and shifts the exponent down. This way, instead of multiplying 
x n times, it reduces the work to about 
logn steps, giving a very efficient solution.*/


code:

double myPow(double x,int n){
 if(n==0)return 1.0;
 if(x==0)return 0.0;
 if(x==1)return 1.0;
 if(x==-1 && n%2==0)return 1.0;
 if(x==-1 && n%2!=0)return -1.0;


 long binForm=n;
 if(binForm<0){
  x=1/x;
  binForm=-binForm;
 }

 double ans=1;
 while(binForm>0){
   if(binForm%2==1({
      ans*=x;
    }
   x*=x;
  binForm/=0;
 }
 return ans;
}

 
