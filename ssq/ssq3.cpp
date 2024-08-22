#include <bits/stdc++.h>
using namespace std;

int s[200001], top = 0;
int n;
int a[200001], ans = 0;

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
        while (top && a[s[top]] < a[i]) {
            top--;
            ans++;
        }
        if (top) {
            ans++;
        }
        s[++top] = i;
    }

    cout << ans;
}