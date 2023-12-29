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
        // Check if the input node is null. If it is, return null since there's nothing to clone.
        if(!node) return nullptr;

        // Create a new node with the same value as the input node. This will be the starting node of the cloned graph.
        Node* newNode = new Node(node->val);

        // Use a stack for DFS traversal of the graph. 
        stack<Node*> st;

        // A hashmap to keep track of cloned nodes. It maps original nodes to their corresponding cloned nodes.
        unordered_map<Node*, Node*> clonedMap;
        
        // Initialize the hashmap with the first node.
        clonedMap[node] = newNode;

        // Start the DFS by pushing the original starting node onto the stack.
        st.push(node);

        // Continue the traversal as long as there are nodes to process in the stack.
        while(!st.empty()) {
            // Pop the top node from the stack. This is the current node being visited.
            auto it = st.top();
            st.pop();

            // Iterate over all the neighbors of the current node.
            for(auto &n : it->neighbors) {
                // Check if the neighbor has been cloned.
                if(clonedMap.find(n) == clonedMap.end()) {
                    // If not, clone it by creating a new node and add it to the hashmap.
                    clonedMap[n] = new Node(n->val);

                    // Also, push the original neighbor to the stack for later processing.
                    st.push(n);
                }
                // Link the clone of the current node to the clone of its neighbor.
                clonedMap[it]->neighbors.push_back(clonedMap[n]);
            }
        }

        // Return the cloned graph starting from the new node.
        return newNode;
    }
};
