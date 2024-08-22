#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1001];

int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cout << edge[i].size() << " ";
    }
}