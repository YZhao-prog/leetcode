#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001], b[1001], f[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[i] = x;
    } 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            } else {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    }

    cout << f[n][m];
}