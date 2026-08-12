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
    unordered_map<Node*,Node*> f;
    Node* dfs(Node* node, Node* cloned_node)
    {
        if(node==nullptr)
            return nullptr;
        for(Node* n :node->neighbors)
        {
            if(f.find(n)==f.end())
            {
                Node* clone=new Node(n->val);
                cloned_node->neighbors.push_back(clone);
                f[n]=clone;
                dfs(n,clone);

            }
            else
            {
                cloned_node->neighbors.push_back(f[n]);
            }
        }
        return cloned_node;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        Node* clone = new Node(node->val);
        f[node]=clone;
        return dfs(node,clone);
    }
};