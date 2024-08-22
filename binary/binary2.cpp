#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[100023];

long long ncount(long long x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < x) {
            sum += (x - a[i]);
        }
    }
    return sum;
}

long long calc(long long k) {
    long long  l = 1, r = 1e14;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (ncount(m) <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
    }

    long long ans = calc(k);
    cout << ans;
}