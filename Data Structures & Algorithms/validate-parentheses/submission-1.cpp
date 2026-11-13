class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets;
        stack<char>bracketStack;
        brackets.insert({'(', ')'});
        brackets.insert({'{', '}'});
        brackets.insert({'[',']'});
        for (const auto &ch: s){
            if (brackets.find(ch) != brackets.end()){
                bracketStack.push(ch);
            }
            else{
                if (bracketStack.empty()) return false;
                char open = bracketStack.top();
                if (brackets[open] == ch){
                    bracketStack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return bracketStack.empty();
    }
};
