#include <bits/stdc++.h>
using namespace std;

int n, k, c;

int a[1000010];
int q[1000010];
int front = 1, rear = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> c;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (front <= rear && a[i] > a[q[rear]]) {
            --rear;
        }
        q[++rear] = i;
        // for (int s = front; s <= rear; s++) {
        //     cout << a[q[s]] << " ";
        // } 
        // cout << "========\n";
        if (i >= c) {
            if (a[q[front]] <= k) {
                ans++;
            }
            if (q[front] + c - 1 <= i) {
                // cout << q[front] << i <<"++\n";
                front++;
            }
        }
    }

    cout << ans;  
}