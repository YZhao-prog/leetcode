#include <bits/stdc++.h>
using namespace std;

int n;
int f[301][301], c[301], a[301];
bool b[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            f[i][j] = x;
        }
    }

    memset(b, false, sizeof(b));
    for (int i = 1 ; i <= n; i++) {
        int x;
        cin >> x;
        c[i] = x;
    }

    for (int l = n; l > 0; l--) {
        int k = c[l];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
        b[k] = true;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (b[i] && b[j]) {
                    ans += f[i][j];
                }
            }
        }
        a[l] = ans;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}