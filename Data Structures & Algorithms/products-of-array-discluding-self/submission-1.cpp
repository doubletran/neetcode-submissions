class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prod_left(n);
        vector<int>prod_right(n);

        int right= nums.size()-2;
        //prod_left = [1, 1, 2, 8]
        //prod_right = [48,24,6,1]
        prod_left[0] = 1;
        prod_right[n-1]  = 1;
        for (int i = 1; i < nums.size(); i++){
            prod_left[i] = prod_left[i-1] * nums[i-1];
            prod_right[right] = prod_right[right+1] * nums[right+1];
            right--;
        }
        for (int i = 0; i < nums.size(); i++){
            nums[i] = prod_left[i] * prod_right[i];
        }

        return nums;
    }
};
