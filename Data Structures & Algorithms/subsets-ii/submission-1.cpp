class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res(1, vector<int>{});
        sort(nums.begin(), nums.end());
        int size = nums.size();
        res.push_back(vector<int>{nums[0]});
        int lastStartPos = 1;
        for (int i = 1; i < size; i++){
            int oldSize = res.size();
            int start = (nums[i] == nums[i-1])? lastStartPos : 0;
            lastStartPos = oldSize;
            for (;start < oldSize; start++){
                vector<int>newSubset = res[start];
                newSubset.push_back(nums[i]);
                res.push_back(newSubset);
            }
        }
        return res;
    }
};
