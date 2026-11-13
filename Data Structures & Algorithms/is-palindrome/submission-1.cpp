class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while (start <= end){

            if (!isalnum(s[start])){
                start += 1;
                continue;
            }
            if (!isalnum(s[end])){
                end -=1;
                continue;
            }
            s[start]  = tolower(s[start]);
            s[end] = tolower(s[end]);
            if (s[start] != s[end]){
                cout << s[start];
                return false;
            }
            start += 1;
            end -=1;
        }
        return true;
    }
};
