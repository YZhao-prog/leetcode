#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[1001], w[1001], a[1001];
vector<int> c[1001];
int f[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = x, v[i] = y, w[i] = z;
        c[a[i]].push_back(i);
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = m; j > 0; j--) {
            for (auto k : c[i]) {
                if (v[k] <= j) {
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
                }
            }
        }
    }
    cout << f[m];
}