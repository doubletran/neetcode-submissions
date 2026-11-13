class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>numbers;
        while (n != 1){
            string n_str = to_string(n);
            n = 0;
            for (auto n_char: n_str){
                n+= (n_char - '0') * (n_char - '0');
            }
            if (numbers.contains(n)){
                return false;
            }
            numbers.insert(n);
        }
        return true;
    }
};
