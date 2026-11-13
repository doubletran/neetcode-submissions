class Node{
    public:
    vector<Node*>children;
    bool endOfWord;
    Node(): children(26, nullptr), endOfWord(false){}
};
class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (auto ch: word){
            if (!curr->children[ch-'a']){
                curr->children[ch-'a'] = new Node();
            }
            curr = curr->children[ch-'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (const auto ch: word){
            if (!curr->children[ch-'a']){
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (const auto ch: prefix){
            if (!curr->children[ch-'a']){
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};
