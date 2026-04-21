class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        // Step 1: Union all swappable indices
        for (auto& swap : allowedSwaps)
            unite(swap[0], swap[1]);

        // Step 2: Group source values by component root
        unordered_map<int, unordered_multiset<int>> comp;
        for (int i = 0; i < n; i++)
            comp[find(i)].insert(source[i]);

        // Step 3: Greedily match target values within same component
        int hamming = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto it = comp[root].find(target[i]);
            if (it != comp[root].end())
                comp[root].erase(it); // matched!
            else
                hamming++;            // can't match → distance +1
        }

        return hamming;
    }
};