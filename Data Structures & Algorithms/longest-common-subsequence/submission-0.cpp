class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // c r a b t
        //c1 1     
        //c1 1 2 2 2 
        //t1 2 3 3 3
        //d
        //b1 2 3 4 
        //t
        //
        vector<vector<int>>grid(text1.length()+1, vector<int>(text2.length()+1, 0));
        int curr  = 1;
        for (int i = 1; i <= text1.length(); i++){
            for (int j = curr; j <= text2.length(); j++){
                grid[i][j] = max(grid[i][j-1], grid[i-1][j]);
                if (text1[i-1] == text2[j-1]){
                    grid[i][j] = max(grid[i-1][j-1] + 1, grid[i][j]);
                }
            }
        }
        return grid[text1.length()][text2.length()];
    }
};
