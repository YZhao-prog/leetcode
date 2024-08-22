#include <bits/stdc++.h>
using namespace std;

char str[511];
int n, f[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        str[i] = c;
    }
    
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            if ((str[j] == '(' && str[j + i] == ')') || (str[j] == '[' && str[j + i] == ']')) {
                f[j][j + i] = f[j + 1][j + i - 1] + 2;
            }
            for (int k = j; k < j + i; k++) {
                f[j][j + i] = max(f[j][j + i], f[j][k] + f[k + 1][j + i]);
            }
        }
    }
    cout << f[1][n];
}