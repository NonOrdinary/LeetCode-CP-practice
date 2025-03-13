class Solution {
public:
    class DSU {
    public:
    //standard DSU but on 2D 
        vector<vector<pair<int, int>>> root;
        vector<vector<int>> rank;
        int components;
        // init
        DSU(int n, int m) {
            root.resize(n, vector<pair<int, int>>(m));
            rank.resize(n, vector<int>(m, 1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    root[i][j] = {i, j};
                    components++;
                }
            }
        }

        pair<int, int> getRoot(int x, int y) {
            if (root[x][y].first == x && root[x][y].second == y) {
                return make_pair(x, y);
            }

            return root[x][y] = getRoot(root[x][y].first, root[x][y].second);
        }

        void Unite(int ax, int ay, int bx, int by) {
            pair<int, int> aRoot = getRoot(ax, ay);
            pair<int, int> bRoot = getRoot(bx, by);
            if (aRoot == bRoot) {
                return;
            }

            if (rank[aRoot.first][aRoot.second] >
                rank[bRoot.first][bRoot.second]) {
                rank[aRoot.first][aRoot.second]++;
                root[bRoot.first][bRoot.second] = aRoot;

            } else {
                root[aRoot.first][aRoot.second] = bRoot;
                rank[bRoot.first][bRoot.second]++;
            }
            components--;
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        DSU dsu(grid.size(), grid[0].size());

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int zCount=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k++) {
                        int nx = dir[k].first + i;
                        int ny = dir[k].second + j;

                        if ((nx >= 0 && nx < grid.size()) && (ny >= 0 &&
                            ny < grid[0].size()) && (grid[nx][ny] == '1')) {
                            dsu.Unite(i, j, nx, ny);
                        }
                    }
                }
                else{
                    zCount++;//zero count incremented
                }
            }
        }
        //initially components=m*n because we also considered 0's,
        // so our final answer should be components-zeroCount
        return dsu.components-zCount;
    }
};