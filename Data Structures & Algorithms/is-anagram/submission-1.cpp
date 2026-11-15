class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freqMap(26, 0);
        for (auto ch: s){
            freqMap[ch-'a']++;
        }
        for (auto ch: t){
            freqMap[ch-'a']--;
        }
        for (auto ch: freqMap){
            if (ch != 0){
                return false;
            }
        }
        return true;
    }
};
