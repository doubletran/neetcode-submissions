class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 1; i < intervals.size(); ++i){
            //make sure that current interval is updated correctly
            if (intervals[i][0] <= intervals[i-1][1]){
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
                intervals[i][0] = intervals[i-1][0];
            }
            else{
                merged.push_back(intervals[i-1]);
            }
        }
        merged.push_back(intervals[intervals.size()-1]);
        return merged;
    }
};
