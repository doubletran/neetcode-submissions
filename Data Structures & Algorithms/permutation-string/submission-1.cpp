class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //l e a c a b e e 
        //[l e c]: 
        //[e c a]
        //[c a b]
        unordered_map<char, int> count;
        vector<int> freq(26, 0);
        vector<int>slidingFreq(26,0);
        for (auto ch: s1){
            freq[ch- 'a']++;
        }
        int start = 0;
        int end = 0;
        int runFreq = 0;
        while (end  < s2.length()){
            slidingFreq[s2[end]-'a']++;
            if (end - start + 1 > s1.length()){
                slidingFreq[s2[start]-'a']--;
                start++;
            }
            if (slidingFreq == freq) return true;
            end++;
        }
        return false;
    }
};
