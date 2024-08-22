#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001];
int l[200001];
int r[200001];
int s[200001];
int top = 0;

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
        while (top != 0 && a[s[top]] >= a[i]) {
            top--;
        }
        if (top) {
            l[i] = s[top];
        } else {
            l[i] = 0;
        }
        s[++top] = i;
    }


    top = 0;
    for (int i = n; i >= 1; i--) {
        while(top != 0 && a[i] <= a[s[top]]) {
            top--;
        }
        if (top) {
            r[i] = s[top];
        } else {
            r[i] = n + 1;
        }
        s[++top] = i;
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << l[i] << " ";
    // }
    // cout << "\n";

    // for (int i = 1; i <= n; i++) {
    //     cout << r[i] << " ";
    // }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1LL * (r[i] - l[i] - 1) * a[i]);
    }
    cout << ans;
}