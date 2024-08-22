#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> edges[100023];
int dist[100023], father[100023][21];

void dfs(int x) {
    for (auto y : edges[x]) {
        dist[y] = dist[x] + 1;
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        father[y][0] = x;
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (father[j][i - 1]) {
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }
    }

    dfs(1);


    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        int x = dist[a], y = dist[b];
        int gap = x - y;
        if (gap > 0) {
            for (int j = 0; j <= 20 && gap; j++, gap /= 2) {
                if (gap & 1) {
                    a = father[a][j];
                }
            }
        } else {
            gap = -gap;
            for (int j = 0; j <= 20 && gap; j++, gap /= 2) {
                if (gap & 1) {
                    b = father[b][j];
                }
            }
        }

        if (a == b) {
            cout << a << "\n";
            continue;
        }

        for (int j = 20; j >= 0; j--) {
            if (father[a][j] != father[b][j]) {
                a = father[a][j];
                b = father[b][j];
            }
        }

        cout << father[a][0] << "\n";
    }
}