class Solution {
    int count = 0;
public:
    void rTarget(vector<int>& nums,int sum, int idx, int target){

        if (idx == nums.size()){
            if (sum == target){
                count++;

            }
            return;
        }

        int plusSum = sum + nums[idx];

        rTarget(nums, plusSum, idx+1, target);
        rTarget(nums, sum - nums[idx], idx+1, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        rTarget(nums, 0, 0, target);
        return count;
    }
};
