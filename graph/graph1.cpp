#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int flag = 1;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        if (x == y || a[x][y] == 1) {
            flag = 0;
        }

        a[x][y] = a[y][x] = 1;

    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}