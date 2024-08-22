#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
int f[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        ans = max(ans, f[i]);
    }

    cout << ans;
}