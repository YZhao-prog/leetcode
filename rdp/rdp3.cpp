#include <bits/stdc++.h>
using namespace std;

int n;
int a[501], f[501][501];
int s[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x, a[i + n] = x;
    }

    memset(f, 127, sizeof(f));
    for (int i = 1; i <= 2 * n; i++) {
        f[i][i] = 0;
    }

    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - i; j++) {
            for (int k = j; k < j + i; k++) {
                f[j][j + i] = min(f[j][j + i], f[j][k] + f[k + 1][j + i] + s[j + i] - s[j - 1]);
            }
        }
    }

    int ans = 1 << 30;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f[i][i + n - 1]);
    }
    cout << ans;
}