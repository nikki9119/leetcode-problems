// Solution for Best Time to Buy and Sell Stock II contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n =prices.size();
        if(n==1) return 0; //return 0 if there is only one day.
        int i=0;
        while(i<n-1){ //loop for the days in the given array.
            while((i<n-1) && (prices[i+1]<=prices[i])) i++; //go to the next day if the price for the next day is less than the price for the present day (in this way we can find the lowest price in the series to buy).
            if(i==n-1) break;
            int buy = prices[i++]; //buy the stock.
            while((i<n)&&(prices[i]>prices[i-1])) i++; //go to the next day if the price for the present day is greater than the price for the previous day (in this way we can find the highest price in the series to sell).
            int sell = prices[i-1]; //sell the stock (get the previous day).
            profit+=sell-buy; //accumulate the profit.
        }
        return profit;
    }
};

// Time complexity: O(n).