class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //  0 1 2 3 4 5
        //1 1 1 1 1 1
        //2 1 1 2 2 3 3
        //3 1 1 2 3 4 5
        //4 1 0

        sort(coins.begin(), coins.end());
        int cSize = coins.size();
        vector<vector<int>>ways(amount+1, vector<int>(coins.size(), 0));
        // initialize
        for (int c = 0; c < coins.size(); c++){
            ways[0][c] = 1;
        }
        for (int i = 1; i <= amount; i++){
            int total = 0;
            for (int c = 0; c < coins.size(); c++){
                int val = coins[c];
                if (val <= i){
                    total +=  ways[i-val][c];
                }
                ways[i][c] = total;
            }
        }
        return ways[amount][cSize-1];
    }
};
