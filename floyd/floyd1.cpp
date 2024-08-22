#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int f[301][301];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;

    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        f[x][y] = v;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][k] < 1 << 30 && f[k][j] < 1 << 30) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if (f[x][y] < 1 << 30) {
            cout << f[x][y] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }


}