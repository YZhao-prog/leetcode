#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200024];

int calc(int x) {
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int calc2(int x) {
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        int ans = calc(x);
        int ans2 = calc2(x) - ans;
        int ans3 = n - ans2 - ans;
        cout << ans << " " << ans2 << " " << ans3 << "\n";
    }
}