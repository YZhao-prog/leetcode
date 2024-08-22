#include <bits/stdc++.h>
using namespace std;

int n, k;

int a[1000100];
long long s[1000100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int x = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (x <= n && s[x] - s[i - 1] <= k) {
            ++x;
        }
        ans = max(ans, x - i);
    }

    cout << ans;
}