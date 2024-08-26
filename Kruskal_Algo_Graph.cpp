class Solution {
public:
    vector<int> parent;
    vector<int> rank;
////////////////////////////// Kruskal Algo ///////////////////////////////////////////////////////
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y) {
            return;
        }
        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int dist(vector<int>& a, vector<int>& b) {
        return abs(b[1] - a[1]) + abs(a[0] - b[0]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Initialize parent and rank vectors
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = dist(points[i], points[j]);
                edges.push_back({i, j, distance});
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        int sum = 0;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (find(u) != find(v)) {
                Union(u, v);
                sum += wt;
            }
        }

        return sum;
    }
};
