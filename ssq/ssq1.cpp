#include <bits/stdc++.h>
using namespace std;

int n;
int s[200111], top = 0;
int ans[200111];
int a[200111];

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
        while (top != 0 && a[s[top]] < a[i]) {
            ans[s[top]] = i;
            top--;
        }
        s[++top] = i;
    }
    while (top != 0) {
        ans[s[top]] = 0;
        top--;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
