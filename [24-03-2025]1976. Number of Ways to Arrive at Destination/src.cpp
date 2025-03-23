public:
    void buildGraph(vector<vector<vector<int>>> &g1, vector<vector<int>> &roads) {
        for (int i = 0; i < roads.size(); i++) {
            int node_1 = roads[i][0];
            int node_2 = roads[i][1];
            int time = roads[i][2];

            g1[node_1].push_back({node_2, time});
            g1[node_2].push_back({node_1, time});
        }
    }

    void modifiedDijkstra(int n, vector<vector<vector<int>>> &g1, vector<int> &paths) {
        const int MOD = 1e9 + 7;
        const long long IMAX = 1e18;
        
        priority_queue<vector<long long>> q1;
        vector<long long> distance(n, IMAX);
        vector<bool> visited(n, false);
        
        distance[0] = 0;
        q1.push({0, 0});

        while (!q1.empty()) {
            vector<long long> ele = q1.top();
            q1.pop();
            int parent = ele[1];

            if (visited[parent]) {
                continue;
            }

            for (int i = 0; i < g1[parent].size(); i++) {
                int child = g1[parent][i][0];
                long long time = g1[parent][i][1];
                long long newDistance = distance[parent] + time;

                if (newDistance < distance[child]) {
                    distance[child] = newDistance;
                    q1.push({-newDistance, child});
                    paths[child] = paths[parent] % MOD;
                } else if (newDistance == distance[child]) {
                    paths[child] = (paths[child] % MOD + paths[parent] % MOD) % MOD;
                }
            }
            visited[parent] = true;
        }
    }

    int countPaths(int n, vector<vector<int>> &roads) {
        vector<vector<vector<int>>> g1(n);
        buildGraph(g1, roads);

        vector<int> paths(n, 0);
        paths[0] = 1;

        modifiedDijkstra(n, g1, paths);
        return paths[n - 1];
    }
};
