class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = 0, sell = 1;
        while (sell < prices.size()){
            if (prices[buy] >= prices[sell]){
                buy = sell;
                sell = sell + 1;
                continue;
            }
            res = max(prices[sell] - prices[buy], res);
            sell += 1;
        }
        return res;
    }
};
