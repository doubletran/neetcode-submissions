class Solution {
public:
    int trap(vector<int>& height) {
        // loop through the water bars
        // find water column instead of water 
        // start = end
        // while end != the next column that at least start
        // sum + water[i] (no start/end)
        // capacity =( end - start ) * min(start, end) - sum
        // water ++
        vector<int>rightMax = height;
        int len = height.size();
        for (int i = len-2; i >= 0;--i){
            rightMax[i] = max(rightMax[i], rightMax[i+1]);
        }
        int maxL = height[0];
        int capacity = 0;
        for (int l = 1; l < len-1; ++l){
            int maxR = rightMax[l+1];
            int cap = min(maxR, maxL) - height[l];
            if (cap >0){
                capacity += cap;
            }
            maxL = max(maxL, height[l]);
        }
        return capacity;
    }
};
