#include <bits/stdc++.h>
using namespace std;

int n, m ,k;
int f[101][101], v[101], w[101],  t[101];

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
        for (int j = m; j >= v[i]; j--) {
            for (int u = k; u >= t[i]; u--) {
                f[j][u] = max(f[j][u], f[j - v[i]][u - t[i]] + w[i]);
            }
        }
    }
    cout << f[m][k];
}