class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];
            pos[num] = i;
        }
        int i = 0;
        for (const int num: nums){
            if (pos.contains(target-num) && pos[target-num]!= i){
                return vector<int>{i, pos[target-num]};
            }
            i++;
        }
        return vector<int>{};
    }
};
