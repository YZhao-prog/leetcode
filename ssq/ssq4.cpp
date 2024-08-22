#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200010];

int q[200010], front = 1, rear = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    int j = 1;

    for (int i = 1; i <=n; i++) {
        while (front - rear - 1 != 0 && a[q[rear]] <= a[i]) {
            rear--;
        }
        q[++rear] = i;
        if (i >= m) {
            if (q[front] + m - 1 < i) {
                front++;
            }
            // for (int i = front; i <= rear; i++) {
            //     cout << a[q[i]] << " ";
            // }
            // cout << "\n";
            cout << a[q[front]] << " ";
        }

    }
}