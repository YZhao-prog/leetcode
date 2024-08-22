#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[1001], v[1001], w[1001], l[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = x, w[i] = y, l[i] = z;
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= l[i]; k++) {
            for (int j = m; j >= v[i]; j--) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
                cout << f[j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    // cout << f[n][m];
}  