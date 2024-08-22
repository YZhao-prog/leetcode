#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100024];
int pre[100024];
int s[100024];
int dist[100024];
int n;

void sumtree(int r) {
    s[r] = 1;
    for (auto x : edge[r]) {
        if (x != pre[r]) {
            pre[x] = r;
            sumtree(x);
            s[r] += s[x];
        }
    }
}

void dfs(int x) {
    for (auto y : edge[x]) {
        if (y != pre[x]) {
            pre[y] = x;
            dist[y] = dist[x] + 1;
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    pre[1] = -1;
    sumtree(1);


    int v = 1 << 30, idx = 0;

    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (auto y : edge[i]) {
            if (y != pre[i]) {
                f = max(f, s[y]);
            } else {
                f = max(f, n - s[i]);
            }
        }
        if (f < v) {
            v = f;
            idx = i;
        }
    }

    memset(pre, 0, sizeof(pre));
    pre[idx] = -1;
    dist[idx] = 0;
    dfs(idx);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dist[i];
    }

    cout << ans;
}