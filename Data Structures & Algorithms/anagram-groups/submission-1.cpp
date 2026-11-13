class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        int id = 0;
        for (const auto& s: strs){
            string str = s;
            sort(str.begin(), str.end());
            anagrams[str].push_back(s);
        }
        vector<vector<string>>result;
        for (auto& pair: anagrams){
            result.push_back(pair.second);
        }
        return result;
        
    }
};
