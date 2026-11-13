class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int res = 0;
        while (left < right){
            if (heights[left] <= heights[right]){
                res = max(heights[left] * (right - left), res);
                left++;
            }
            else{
                res = max(heights[right] * (right-left), res);
                right--;
            }
        }
        return res;
    }
};
