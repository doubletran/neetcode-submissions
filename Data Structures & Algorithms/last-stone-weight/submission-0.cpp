class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>stone_queue;
        for (auto stone: stones){
            stone_queue.push(stone);
        }
        while (stone_queue.size() > 1){
            int y = stone_queue.top();
            stone_queue.pop();
            int x = stone_queue.top();
            stone_queue.pop();
            cout << y;
            if (x== y) continue;
            if (x < y){
                stone_queue.push(y-x);
            }
        }
        if (stone_queue.empty()) return 0;
        else{
            return stone_queue.top();
        }
    }
};
