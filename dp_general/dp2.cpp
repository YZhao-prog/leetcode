#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001], f[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(a, 127, sizeof(a));

    for (int i = 1; i <= m; i++) {
        int x, y ,v;
        cin >> x >> y >> v;
        a[x][y] = min(a[x][y], v);
    }

    memset(f, 127, sizeof(f));

    f[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (f[j] < 1 << 30 && a[j][i] < 1 << 30) {
                f[i] = min(f[i], f[j] + a[j][i]);
            }
        }
    }

    cout << f[n];
}