class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        unordered_set<int> visited;
        int count =0;
        for (const auto & edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int>q;
        for (int i = 0; i < n; i++){
            if (visited.find(i) != visited.end()) continue;
            count++;
            q.push(i);
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                visited.insert(curr);
                for (auto adj: graph[curr]){
                    if (visited.find(adj) != visited.end()) continue;
                    visited.insert(adj);
                    q.push(adj);
                }
            }
        }
        return count;
    }
};
