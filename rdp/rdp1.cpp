#include <bits/stdc++.h>
using namespace std;

int n, a[501], s[501];

int solve(int l, int r) {
    if (l == r) {
        return 0;
    }
    int ans = 1 << 30;
    for (int m = l; m < r; m++) {
        ans = min(ans, solve(l, m) + solve(m + 1, r));
    }
    return ans + s[r] - s[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {      
        int x;
        cin >> x;
        a[i] = x;
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int ret = solve(1, n);
    cout << ret;
}