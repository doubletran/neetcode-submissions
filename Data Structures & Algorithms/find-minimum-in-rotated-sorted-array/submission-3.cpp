class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        if (nums[0] <= nums[size-1]) return nums[0];
        int left = 0;
        int right = size-1;
        while (left < right-1){
            int mid = left + ((right-left)/2);
            if (nums[mid] < nums[right]){
                right = mid;
            }
            else if (nums[mid]> nums[left]){
                left = mid;
            }
        }
        return nums[right];
    }
};
