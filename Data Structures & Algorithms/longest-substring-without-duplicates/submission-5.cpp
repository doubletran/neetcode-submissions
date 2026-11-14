class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> posMap;
        int start = 0;
        int maxLen = 0;
        int i = 0;
        for (; i < s.size(); ++i){
            if (posMap.contains(s[i])){
                maxLen = max(maxLen, i - start);
                start = max(posMap[s[i]]+1, start);
            }
            posMap[s[i]] = i;
        }
        return max(maxLen, i - start);
    }
};
