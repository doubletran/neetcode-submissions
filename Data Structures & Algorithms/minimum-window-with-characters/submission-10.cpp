class Solution {
public:
    string minWindow(string s, string t) {
        string minRes = "";
        bool updated = false;
        unordered_map<char, int>tmap;
        unordered_map<char, int>smap;
        queue<int>matched;
        int start = 0;
        int s_len = s.size();
        pair<int, int> window = {-1, s_len};
        for (auto &ch : t){
            tmap[ch]++;
        }
        while (start < s_len){
            if (tmap.contains(s[start])) break;
            ++start;
        }     
        if (start == s_len || t.size() > s_len) return "";
        int pointer = t.size();
        for (int i  = start; i < s_len; ++i){
            auto &ch = s[i];
            if (tmap.contains(ch)){
                if (smap[ch] < tmap[ch]){
                    pointer--;
                }
                smap[ch]++;
                if (i != start) matched.push(i);
                while (pointer == 0){
                    if (i - start + 1 < window.second - window.first + 1){
                        window = {start, i};
                    }
                    smap[s[start]]--;
                    pointer = pointer + ((tmap[s[start]] <= smap[s[start]]) ? 0:1);
                    start = matched.front();
                    matched.pop();
                }
            }
        }
        minRes = (window.first == -1) ? "": s.substr(window.first, window.second - window.first + 1);
        return minRes;

    }
};
