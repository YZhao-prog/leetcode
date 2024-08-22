#include <bits/stdc++.h>

using namespace std;

int z[200034];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int c = 0; c < t; c++) {

        string str1, str2;

        cin >> str1 >> str2;

        int s1 = str1.length();
        int s2 = str2.length();

        str2.push_back('#');
        str2.append(str1);
        // cout << str2 << "\n";

        int L = 1, R = 0, cnt = 0;
        z[0] = 0;
        for (int i = 1; i < s1 + s2 + 1; i++) {
            if (i > R) {
                z[i] = 0;
            } else {
                int k = i - L;
                z[i] = min(z[k], R - i + 1);
            }

            while (i + z[i] < s1 + s2 + 1 && str2[z[i] + i] == str2[z[i]]) {
                z[i]++;
            }
            if (z[i] == s2) {
                ++cnt;
            }
            if (i + z[i] - 1 > R) {
                L = i;
                R = i + z[i] - 1;
            }
        }

        if (cnt == 0) {
            cout << -1 << "\n" << -1 << "\n";
            continue;
        }

        cout << cnt << "\n";
        for (int i = s2 + 1; i < s1 + s2 + 1; i++) {
            if (z[i] == s2) {
                cout << i - s2 << " ";
            }
        }
        cout << "\n";
    }
}