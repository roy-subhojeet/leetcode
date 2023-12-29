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
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* newNode = new Node(node->val);
        stack<Node*> st;
        unordered_map<Node*, Node*> clonedMap; //neat trick to use hash map to map old nodes to new ones
        clonedMap[node] = newNode;
        st.push(node);
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            for(auto &n : it->neighbors)
            {
                if(clonedMap.find(n) == clonedMap.end()) // if not visited
                {
                    st.push(n); // add to stack to be visited
                    clonedMap[n] = new Node(n->val);
                }
                clonedMap[it]->neighbors.push_back(clonedMap[n]);
            }
        }

        return newNode;

    }
};