class Solution {
public:

    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& point){
            return sqrt(pow(point[0], 2) + pow(point[1], 2));};
        auto compare = [dist](const vector<int>& pt1, const vector<int>& pt2){
            return dist(pt1) < dist(pt2);};
        sort(points.begin(), points.end(), compare);
        vector<vector<int>>closet;
        for (int i = 0; i < points.size() && i < k; i++){
            closet.push_back(points[i]);
        }
        return closet;
    }
};
