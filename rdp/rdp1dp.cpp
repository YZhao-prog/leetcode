#include <bits/stdc++.h>
using namespace std;

int n, a[501], s[501], f[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            for (int k = j; k < j + i; k++) {
                f[j][j + i] = min(f[j][j + i], f[j][k] + f[k + 1][j + i] + s[j + i] - s[j - 1]);
            }
        }
    }
    cout << f[1][n];

}