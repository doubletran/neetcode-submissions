typedef vector<unordered_set<int>> Hash;
class Solution {
public:
//  0 1 2 3
//0 0,0  0,1
//1
//2 1,0 1, 1 
//3

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<Hash> hashPosition(9, Hash(3, unordered_set<int>{}));
        int nrow = board.size();
        for (int i = 0; i < nrow; i++){
            for (int j = 0; j < nrow; j++){
                if (board[i][j]== '.') continue;
                int num = board[i][j]-'0'-1;
                if (hashPosition[num][0].find(i) != hashPosition[num][0].end()) return false;
                if (hashPosition[num][1].find(j) != hashPosition[num][1].end()) return false;
                int grid = (i/3)*3 + j/3;
                cout << grid <<endl;
                if (hashPosition[num][2].find(grid) != hashPosition[num][2].end()) return false;
                hashPosition[num][0].insert(i);
                hashPosition[num][1].insert(j);
                hashPosition[num][2].insert(grid);
            }
        }
        return true;
    }
};
