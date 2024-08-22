#include <bits/stdc++.h>
using namespace std;

int z[2000023];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.length();

    z[0] = 0;
    int L = 1, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            z[i] = 0;
        } else {
            int k = i - L;
            z[i] = min(z[k], R - i + 1);
        }
        while (i + z[i] < n && str[z[i] + i] == str[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << z[i];
    // }
    // cout << "\n";

    int ans = 0, x = 0;
    for (int i = 0; i < n; i++) {
        if (i + z[i] == n) {
            if (x >= z[i]) {
                ans = max(ans, z[i]);
            }
        }
        x = max(x, z[i]);
    }

    if (ans == 0) { 
        cout << "Just a legend";
        return 0;
    }
    for (int i = 0; i < ans; i++) {
        cout << str[i];
    }
}