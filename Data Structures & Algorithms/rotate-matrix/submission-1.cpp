class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
// 4 8
// 3 6
//3 4
//6 8
//start =1
// end = 2
        int size = matrix.size();
        vector<int>moveVect(size, 0);
        for (int start = 0; start < size/2; start++){ 
            int end = size - start -1;
            for (int i = start; i < end; i++){
                swap(matrix[start][i], matrix[i][end]);
                swap(matrix[start][i], matrix[end-(i-start)][start]);
                swap(matrix[end-(i-start)][start], matrix[end][end - (i-start)]);
            }
        }
        

    }
};
