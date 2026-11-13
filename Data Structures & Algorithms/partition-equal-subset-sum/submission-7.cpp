class Solution {
public:
 //  1 2 4 5 6
 //0 T T T T T
 //1 T 
 //2 0 T 
 //3 0 T
 //4 0 0 T
 //5 0 0 0 T 
 //6 0 0 T 0 T
 //7 0 0 T 0 0
 //8
    bool targetSum(vector<int>& sortedNums, int target){
        vector<vector<bool>>validSum(target + 1, vector<bool>(sortedNums.size(), false));
        for (int n = 0; n < sortedNums.size(); n++){
            validSum[0][n] = true;
        }
        validSum[sortedNums[0]][0] = true;
        for (int i = 1; i <= target; i++){
            for (int n = 1; n < sortedNums.size(); n++){
                int num = sortedNums[n];
                if (num > i) {
                    validSum[i][n] = validSum[i][n-1];
                    continue;
                }
                validSum[i][n] = validSum[i-num][n-1];
                cout << validSum[i][n] << " ";
            }
            cout <<endl;
        }
        return validSum[target][sortedNums.size()-1];
    }
    bool canPartition(vector<int>& nums) {
        // 2 4 1 4 5
        if (nums.size() == 1) return false;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        sort(nums.begin(), nums.end());

        totalSum = totalSum / 2;
        return targetSum(nums, totalSum);
    }
};
