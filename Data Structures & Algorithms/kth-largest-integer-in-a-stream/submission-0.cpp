class KthLargest {
    int order;
    priority_queue<int>q;

public:
    KthLargest(int k, vector<int>& nums) {
        order = k;
        for (const auto & num: nums){
            q.push(num);
        }

    }
    
    int add(int val) {
        q.push(val);
        auto it = q;
        int res =it.top();
        for (int i = 0; i < order; i++){
            res = it.top();
            it.pop();
        }
        return res;
    }
};
