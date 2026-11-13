class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            //0 1 2 3 4 5 6 7 8 9 10
        //1     1   
        //2       1
        //6     
        //   1
        //10 1
        vector<int> minAmount(amount+1, amount+ 1);
        minAmount[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i < amount + 1; i++){
            for (auto c : coins){
                if (c > i) break;
                minAmount[i] = min(minAmount[i - c] + 1, minAmount[i]);
                
            }
        }
        return minAmount[amount] == amount + 1 ? -1: minAmount[amount];
    }
};
