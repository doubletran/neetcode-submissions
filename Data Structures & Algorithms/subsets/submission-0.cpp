class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res(1, vector<int>{});
        for (const auto & num: nums){
            int oSize  = res.size();
            for (int i = 0; i < oSize; i++){
                vector<int>newSubset = res[i];
                newSubset.push_back(num);
                res.push_back(newSubset);
            }
        }
        return res;
    }
};
