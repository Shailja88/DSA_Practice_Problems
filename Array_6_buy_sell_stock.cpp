// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Best Time to Buy and Sell Stock


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        //tc = O(n^2)
        //SC=O(1)
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
          
            for(int j=i+1;j<n;j++){
             profit=max(profit,(prices[j]-prices[i]));
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        //tc = O(n)
        //SC=O(n)
        
        int profit=0;
        int n=prices.size();
        vector<int>store_min_val(n,0);
        store_min_val[0]=prices[0];
        for(int i=1;i<n;i++){
            store_min_val[i]=min(store_min_val[i-1],prices[i]);
        }

        for(int i=0;i<n;i++){
            int val=prices[i]-store_min_val[i];
            profit=max(val,profit);
        }
        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        //tc = O(n)
        //SC=O(1)
        int mini=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int val=prices[i]-mini;
            profit=max(profit,val);
              mini=min(prices[i],mini);
        }
        return profit;

    }
    };

