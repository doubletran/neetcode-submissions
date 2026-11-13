class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, bool> hashmaps;
        for (auto n: nums){
            hashmaps[n]= !hashmaps[n];
        }
        for (auto [key, value]: hashmaps){
            if (value == true){
                return key;
            }
        }
        return 0;
    }
};
