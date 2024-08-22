#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<double, int>> q;
double dist[1001];
bool b[1001];
int points[801][2];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i][0] = x;
        points[i][1] = y;
    }
    for (int i = 0; i < n; i++) {
        dist[i] = 1e100;
    }
    memset(b, false, sizeof(b));
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        q.insert(make_pair(dist[i], i));
    }

    double ans = 0;
    while (!q.empty()) {
        int x = q.begin()->second;
        q.erase(q.begin());
        if (dist[x] > 1e99) {
            cout << x << dist[x];
            break;
        }
        ans += dist[x];
        b[x] = true;
        for (int i = 0; i < n; i++) {
            if (b[x] == false) {
                continue;
            }
            int ax = points[x][0], ay = points[x][1];
            int bx = points[i][0], by = points[i][1];
            double dis = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
            if (!b[i] && dist[i] > dis) {
                q.erase(make_pair(dist[i], i));
                dist[i] = dis;
                q.insert(make_pair(dist[i], i));
            }
        }

    }
    cout << fixed << setprecision(1) << ans;
}