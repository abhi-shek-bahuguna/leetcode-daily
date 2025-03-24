class Solution {
public:
    void buildTree(vector<vector<int>> &g1, vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            int node_1 = edges[i][0];
            int node_2 = edges[i][1];
            g1[node_1].push_back(node_2);
            g1[node_2].push_back(node_1);
        }
    }

    void markVisited(vector<bool> &visited, vector<int> &restricted) {
        for (int i = 0; i < restricted.size(); i++) {
            visited[restricted[i]] = true;
        }
    }

    void dfs(vector<vector<int>> &g1, vector<bool> &visited, int parent, int &countVisited) {
        if (visited[parent]) {
            return;
        }

        visited[parent] = true;
        countVisited++;

        for (int i = 0; i < g1[parent].size(); i++) {
            dfs(g1, visited, g1[parent][i], countVisited);
        }
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        vector<vector<int>> g1(n);
        buildTree(g1, edges);
        
        vector<bool> visited(n, false);
        markVisited(visited, restricted);
        
        int countVisited = 0;
        dfs(g1, visited, 0, countVisited);
        
        return countVisited;
    }
};
