/*<<<<<Best time to buy and sell stock>>>>>*/


/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

/*This solution solves the Best Time to Buy and Sell Stock problem in one pass by tracking the lowest buying price and the maximum profit so far.
 It initializes bestBuy as the first day’s price and maxProf as 0. 
Then, for each day’s price, it checks if selling today would give a better profit (prices[i] - bestBuy) than the current maxProf, and updates accordingly.
 At the same time, it updates bestBuy to always hold the minimum price seen so far, ensuring you always compare with the cheapest possible buy before today. 
This guarantees that the maximum profit is found in O(n) time and O(1) space, since you only scan the array once while keeping two variables.*/

code:

int maxProfit(vector<int>&prices){
  int maxProf=0;
  int bestBuy=prices[0];
  for(int i=1;i<prices.size();i++){
     if(prices[i]>bestBuy){
        maxProf=max(maxProf,prices[i]-bestBuy);
     }
     bestBuy=min(bestBuy,prices[i]);
   }
 return maxProf;
}
