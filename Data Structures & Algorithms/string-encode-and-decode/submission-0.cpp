class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto s: strs){
            encoded += to_string(s.size());
            encoded += '_';
            encoded += s;
        }
        cout << encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for (int i = 0; i < s.size(); ){
            string num;
            while ((i < s.size()) && (s[i] != '_')){
                num += s[i];
                i++;
            }

            cout << num;
            i++;
            int count = stoi(num);
            string cur = s.substr(i, count);
            i+= count;
            decoded.push_back(cur);
        }
        return decoded;
    }
};
