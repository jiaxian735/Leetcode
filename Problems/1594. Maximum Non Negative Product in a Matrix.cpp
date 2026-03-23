class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long m = grid.size(), n = grid[0].size(), mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> v(m, vector<pair<long long, long long>>(n, { 0, 0 }));
        v[0][0] = { grid[0][0], grid[0][0] };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool change = false;
                if (i > 0) {
                    long long temp1 = (v[i - 1][j].first * grid[i][j]), temp2 = (v[i - 1][j].second * grid[i][j]);
                    if (temp1 < temp2) swap(temp1, temp2);
                    v[i][j] = { temp1, temp2 };
                    change = true;
                }
                if (j > 0) {
                    long long temp1 = (v[i][j - 1].first * grid[i][j]), temp2 = (v[i][j - 1].second * grid[i][j]);
                    if (temp1 < temp2) swap(temp1, temp2);
                    if (change) {
                        v[i][j].first = max(v[i][j].first, temp1);
                        v[i][j].second = min(v[i][j].second, temp2);
                    }
                    else
                        v[i][j] = { temp1, temp2 };
                }
            }
        }
        long long ans = max(v[m - 1][n - 1].first, v[m - 1][n - 1].second);
        return (ans >= 0 ? ans % mod : -1);
    }
};