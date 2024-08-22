#include <bits/stdc++.h>
using namespace std;

int n, a[501], s[501], f[501][501];

// 记忆化搜素
int solve(int l, int r) {
    if (f[l][r] != -1) {
        return f[l][r];
    }
    if (l == r) {
        f[l][r] = 0;
        return 0;
    }
    int ans = 1 << 30;
    for (int m = l; m < r; m++) {
        ans = min(ans, solve(l, m) + solve(m + 1, r));
    }
    f[l][r] = ans + s[r] - s[l - 1];
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

    memset(f, 255, sizeof(f));
    int ret = solve(1, n);
    cout << ret;
}