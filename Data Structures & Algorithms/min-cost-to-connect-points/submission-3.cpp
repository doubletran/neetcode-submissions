typedef pair<int, pair<int,int>> pi;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pi, vector<pi>, greater<pi>>q;
        vector<unordered_set<int>>visitedSets;
        int minCost = 0;
        for (int i =0; i < points.size(); i++){
            for (int j = i + 1; j < points.size(); j++){
                if (i == j) continue;
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                cout <<cost <<endl;
                q.push({cost, {i, j}});
            }
        }

        while (!q.empty()){
            auto curr = q.top();
            q.pop();
            auto node1 =curr.second.first;
            auto node2 = curr.second.second;
            cout << node1 << " " << node2 <<endl;
            bool cycle = false;
            bool visited = false;
            int node1_setId = -1;
            int node2_setId = -1;
            for (int i = 0; i < visitedSets.size(); i++){
                auto visitedSet = visitedSets[i];
                auto bFindNode1 = visitedSet.find(node1) != visitedSet.end();
                auto bFindNode2 = visitedSet.find(node2) != visitedSet.end();
                if (bFindNode1 && bFindNode2){
                    cycle = true;
                    break;
                }
                if (bFindNode1){
                    node1_setId = i;
                }
                if (bFindNode2){
                    node2_setId = i;
                }
            }
            if (cycle) continue;
            if (node1_setId == -1){
                if (node2_setId == -1){
                    visitedSets.push_back(unordered_set<int>{node1, node2});
                }
                else{
                    visitedSets[node2_setId].insert(node1);
                }
            }
            else{
                if (node2_setId == -1){
                    visitedSets[node1_setId].insert(node2);
                    
                }
                else{
                    visitedSets[node1_setId].insert(visitedSets[node2_setId].begin(),visitedSets[node2_setId].end());
                    visitedSets.erase(visitedSets.begin() + node2_setId);
                }
            }
            minCost += curr.first;
        }
        return minCost;
    }
};
