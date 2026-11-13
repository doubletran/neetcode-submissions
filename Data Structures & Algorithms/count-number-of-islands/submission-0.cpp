class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int nrows = grid.size();
        int ncols = grid[0].size();
        int num = 0;
        queue<vector<int>>island;
        for (int r =0; r < nrows; r++){
            for (int c = 0; c < ncols; c++){
                if (grid[r][c] == '1'){
                    island.push(vector<int>{r,c});
                    while (!island.empty()){
                        vector<int>pos = island.front();
                        island.pop();
                        if (grid[pos[0]][pos[1]] != '1') continue;
                        grid[pos[0]][pos[1]] ='0';
                        if (pos[0] > 0) island.push(vector<int>{pos[0]-1, pos[1]});
                        if (pos[0] < nrows-1) island.push(vector<int>{pos[0]+1, pos[1]});
                        if (pos[1] > 0) island.push(vector<int>{pos[0], pos[1]-1});
                        if (pos[1] < ncols-1) island.push(vector<int>{pos[0], pos[1]+1});
                    }
                    cout << r << endl; 
                    cout << c << endl;
                    num += 1;
                }         
            }   
        }
        return num;
    }
};
