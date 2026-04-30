class Solution {
public:
    TreeNode* first = NULL;  // will store the starting node

    // Step 1: Create child → parent mapping
    void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;

        // If left child exists, map it to its parent
        if (root->left) parent[root->left] = root;

        // If right child exists, map it to its parent
        if (root->right) parent[root->right] = root;

        // Traverse left and right subtree
        mapping(root->left, parent);
        mapping(root->right, parent);
    }

    // Step 2: Find the node from where fire starts
    void find(TreeNode* root, int start) {
        if (!root) return;

        // If current node matches start value, store it
        if (root->val == start) first = root;

        // Search in left and right subtree
        find(root->left, start);
        find(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        // Edge case: empty tree
        if (!root) return 0;

        // Step 2: locate the starting node
        find(root, start);

        // Safety check: if start node not found
        if (!first) return 0;

        // Step 1: build parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        mapping(root, parent);

        // Step 3: BFS to simulate fire spreading
        unordered_set<TreeNode*> visited;   // to avoid revisiting nodes
        queue<pair<TreeNode*, int>> q;      // stores {node, time}

        // Initialize BFS with starting node
        q.push({first, 0});
        visited.insert(first);

        int maxTime = 0;  // stores final answer

        // Step 4: BFS traversal
        while (!q.empty()) {
            auto [node, time] = q.front();
            q.pop();

            // Update maximum time
            maxTime = max(maxTime, time);

            // Spread fire to left child
            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push({node->left, time + 1});
            }

            // Spread fire to right child
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push({node->right, time + 1});
            }

            // Spread fire to parent
            if (parent.count(node) && !visited.count(parent[node])) {
                visited.insert(parent[node]);
                q.push({parent[node], time + 1});
            }
        }

        // Step 5: return total time required to burn tree
        return maxTime;
    }
};