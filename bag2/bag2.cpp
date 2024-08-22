#include <bits/stdc++.h>
using namespace std;

int n, m ,k;
int f[101][101][101], v[101], w[101], t[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = x, w[i] = y, t[i] = z;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int u = 1; u <= k; u++) {
                if (j < v[i] || u < t[i]) {
                    f[i][j][u] = f[i - 1][j][u];
                } else {
                    f[i][j][u] = max(f[i - 1][j][u], f[i - 1][j - v[i]][u - t[i]] + w[i]);
                }
            }
        }
    }
    cout << f[n][m][k];
}