#include <iostream>
#include <vector>

std::vector<std::vector<int>> prefix_sum_2d(const std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    std::vector<std::vector<int>> ps(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ps[i][j] = mat[i][j];
            if (i > 0) ps[i][j] += ps[i - 1][j];
            if (j > 0) ps[i][j] += ps[i][j - 1];
            if (i > 0 && j > 0) ps[i][j] -= ps[i - 1][j - 1];
        }
    }
    return ps;
}

int query_2d(const std::vector<std::vector<int>>& ps, int x1, int y1, int x2, int y2) {
    int res = ps[x2][y2];
    if (x1 > 0) res -= ps[x1 - 1][y2];
    if (y1 > 0) res -= ps[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) res += ps[x1 - 1][y1 - 1];
    return res;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto ps = prefix_sum_2d(mat);
    std::cout << query_2d(ps, 1, 1, 2, 2) << "\n";
}
