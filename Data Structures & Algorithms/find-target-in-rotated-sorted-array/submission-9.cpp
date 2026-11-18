class Solution {
public:
    int search(vector<int>& nums, int target) {

        //5 1 2 3 4
        //start = 0, end = 4 -> mid = 2
        //3 4 5 6 1 2
        if (nums.size()  == 0) return -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end-1){
            int mid = start + ((end - start)/2);
            if (target == nums[mid]){ return mid;}
            if (target < nums[mid]){
                if (target >= nums[start] || nums[start] > nums[mid]){
                    end = mid;
                }
                else {
                    start = mid;
                }
            }
            else if (target > nums[mid]){
                if (target <= nums[end] || nums[mid]  > nums[end]){
                    start = mid;
                }
                else{
                    end = mid;
                }
            }
        }
        if (target == nums[end]) return end;
        if (target == nums[start]) return start;
        return -1;
    }
};
