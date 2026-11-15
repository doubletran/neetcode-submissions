class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums;
        unordered_map<int, int>stored_length;
        //[2, 20, 4, 10, 3, 5] set
        //len = 4, num =4
        //stored_length: <2, 4>, <20, 1>, <4, 2>, <10, 1>, <3, 3>, <
        for (auto &n: nums){
            unique_nums.insert(n);
        }
        int maxLen = 0;
        for (const int num: unique_nums){
            int len = 1;
            while (unique_nums.contains(num+len)){
                if (stored_length.contains(num+len)){
                    len+= stored_length[num+len];
                    break;
                }
                len++;
            }
            stored_length.insert({num, len});
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};
