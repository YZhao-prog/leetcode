#include <bits/stdc++.h>
using namespace std;

int a[9][9], b[9][9], c[9], r[9];
int n, m;

bool dfs(int x) {
    if (x == n + 1) {
        bool ok = true;
        for (int i = 1; i <= n && ok; i++) {
            for (int j = i + 1; j <= n && ok; j++) {
                if (a[i][j] != b[c[i]][c[j]]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            return true;
        } else {
            return false;
        }

    }

    for (int i = 1; i <= n; i++) {
        if (!r[i]) {
            c[x] = i;
            r[i] = true;
            if (dfs(x + 1)) {
                return true;
            }
            r[i] = false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        b[x][y] = b[y][x] = 1;
    }

    if (dfs(1)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}