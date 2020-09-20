class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if (!root) return res;
        res.push_back(root -> val);
        for (auto i : root -> children) {
            preorder(i);
        }
        return res;
        
    }
};