#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> edges[1001];
set<pair<int, int>> q;
int dist[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        edges[x].push_back(make_pair(y, v));
    }
    memset(dist, 127, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        q.insert(make_pair(dist[i], i));
    }
    while (!q.empty()) {
        int x = q.begin()->second;
        q.erase(q.begin());

        if (x == n || dist[x] > 1 << 30) {
            break;
        }
      
        for (auto i : edges[x]) {
            if (dist[i.first] > i.second + dist[x] && i.first > x) {
                q.erase(make_pair(dist[i.first], i.first));
                dist[i.first] = i.second + dist[x];
                q.insert(make_pair(dist[i.first], i.first));
            }
        }
    }

    cout << dist[n];
}