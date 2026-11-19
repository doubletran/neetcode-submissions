class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //[-4, -1, -1, 0, 1, 2, 3]
        //loop from left to right
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        int maxR = nums.size()-1;
        int i = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) break;
            int l = i+1;
            int r = maxR;
            if ((i > 0) && (nums[i]== nums[i-1])){
                continue;
            }
            while (l < r){
                if (r < maxR && nums[r] == nums[r+1]){
                    --r;
                    continue;
                }
                int sum = nums[r] + nums[i] + nums[l];
                if (sum == 0){
                    res.push_back({nums[i],nums[l], nums[r]});
                    ++l;
                    --r;
                }
                else if (sum > 0){
                    --r;
                }
                else{
                    ++l;
                }
            }
        }
        return res;
    }
};
