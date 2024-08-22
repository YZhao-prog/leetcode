#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[1001], v[1001], w[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = x, w[i] = y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m];
}