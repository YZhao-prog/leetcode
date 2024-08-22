#include <bits/stdc++.h>
using namespace std;

int n, m;

set<pair<int, int>> q;

vector<pair<int, int>> edges[50001];

int dist[50001];
bool b[50001];

int prim(int s) {
    memset(b, false, sizeof(b));
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        q.insert(make_pair(dist[i], i));
    }

    int tot = 0;
    while (!q.empty()) {
        int x = q.begin()->second;
        q.erase(q.begin());
        b[x] = true;

        if (dist[x] > 1 << 30) {
            break;
        }
        tot += dist[x];

        for (auto i : edges[x]) {
            if (b[i.first] == false && dist[i.first] > i.second) {
                q.erase(make_pair(dist[i.first], i.first));
                dist[i.first] = i.second;
                q.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        edges[x].push_back(make_pair(y, v));
        edges[y].push_back(make_pair(x, v));
    }

    int ans = prim(1);
    cout << ans;
}