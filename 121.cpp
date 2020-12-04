/*
121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
             
Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

solve
第一种暴力求解，超时
第二种使用两个指针，一个指向卖的，一个买的，当卖的所指大于买的，记录并与前面的大值比较，当卖的小于买的所指，说明从当前位置往后走，应该使用当前位置作为买的
第三种动态规划，两两做差值，相当于求和最大的子串，当前的差值加上前面累计的大于当前的，累计上当前的，如果小于，直接以当前的重新开始；然后与前面存的大值比较 
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return NULL;
        int i;
        int max = 0;
        for(i = 0; i < prices.size()-1; ++i){
            if(i!=0 && prices[i]>prices[i-1]) continue;
            int max_tmp;
            int j;
            for(j = i+1; j < prices.size(); ++j){
                if(prices[j]>prices[i]){
                    max_tmp = prices[j]-prices[i];
                    if(max_tmp>max) max = max_tmp;
                }
            }
        }
        return max;
    }
    
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i=0, j=0; j < prices.size();++j){
            if(prices[j]>prices[i]){
                max = max>(prices[j]-prices[i])?max:(prices[j]-prices[i]);
            }
            else i = j;
        }
        return max;
    }
    
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int max_tmp = 0;
        for(int i=1; i < prices.size();++i){
            int tmp = prices[i] - prices[i-1];
            max_tmp = (max_tmp+tmp) > tmp?(max_tmp+tmp):tmp;
            max = max>max_tmp?max:max_tmp;
        }
        return max;
    }
};
