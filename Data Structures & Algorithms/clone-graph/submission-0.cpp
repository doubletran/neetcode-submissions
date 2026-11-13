/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<Node*> newNeighbors;
        Node* newNode = new Node(node->val);
        this->visited.insert({node->val, newNode});
        for ( auto &neighbor: node->neighbors){
            if (this->visited.find(neighbor->val) != visited.end()){
                newNode->neighbors.push_back(visited[neighbor->val]);
                continue;
            }
            Node * newNeighbor = cloneGraph(neighbor);
            if (newNeighbor){
                newNode->neighbors.push_back(newNeighbor);
            }
        }
        return newNode;
    }
};
