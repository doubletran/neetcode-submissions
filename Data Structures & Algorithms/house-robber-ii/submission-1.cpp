class Solution {
public:
    int rob(vector<int>& nums) {
        //10, 9, 3, 10, 0, 2
        int prev = 0, pprev = 0;
        int prevNohead = 0, pprevNohead = 0;
        prev = nums[0];
        for (int i = 1; i < nums.size()-1; i++){
            int curr = max(pprev + nums[i], prev);
            pprev = prev;
            prev = curr;
        
            curr = max(pprevNohead + nums[i], prevNohead);
            pprevNohead = prevNohead;
            prevNohead = curr;
        }
        int maxNohead =max(pprevNohead + nums[nums.size()-1],prevNohead);
        return max(maxNohead, prev);

    }
};
