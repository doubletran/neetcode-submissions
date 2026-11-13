class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> speedi;
        for (int i =0; i < position.size(); i++){
            speedi.insert({position[i], speed[i]});
        }
        int count = 0;
        double prevFleetTime =0;
        for (auto i: speedi){
            cout << i.first;
            if (double(target - i.first)/i.second <= prevFleetTime){
                continue;
            }
            prevFleetTime  = double(target - i.first)/i.second;
            count++;
        }
        return count;
        
    }
};
