class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        int size = nums.size();

        for (int i = 0; i < size - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = size - 1;
            while (l < r){
                int target = -nums[i];
                if (nums[l] + nums[r] < target){
                    l += 1;
                }
                else if (nums[l] + nums[r] > target){
                    r -=1;
                }
                else{
                    vector<int>triplet {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    l+= 1;
                    r-=1;
                    while (l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
