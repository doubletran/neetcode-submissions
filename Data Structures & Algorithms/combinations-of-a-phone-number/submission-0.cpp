class Solution {
    vector<vector<char>>mapper{8, vector<char>{}};
    string digits;
public:
    vector<string> rLetterCombinations(int pos){
        if (pos == digits.length()) return {};
        vector<string>combo;
        int iDigit = digits[pos] - '2';
        cout << iDigit;
        if (pos == digits.length()-1) {
            for (auto ch: mapper[iDigit]){
                string cstr(1, ch);
                combo.push_back(cstr);
            }
            return combo;
        }
        auto suffixes = rLetterCombinations(pos+1);
        for (auto ch: mapper[iDigit]){
            for (auto suffixStr : suffixes){
                string newStr = ch + suffixStr;
                combo.push_back(newStr);
            }
        }
        return combo;
    }
    vector<string> letterCombinations(string digits) {

        char curr = 'a';
        for (int i = 0; i < mapper.size(); i++){
            int count = 3;
            if (i ==5 || i == 7){
                count = 4;
            }
            while (count > 0){
                mapper[i].push_back(curr);
                curr++;
                count--;
            }
        }
        this->digits = digits;
        return rLetterCombinations(0);

    }
};
