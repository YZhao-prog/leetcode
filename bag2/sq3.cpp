#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001];
int n;

int q[100001], front = 1, rear = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = x, b[i] = y;
    }

    for (int i = 1; i <= n; i++) {
        while (front <= rear && b[q[rear]] <= b[i]) {
            --rear;
        }
        q[++rear] = i;
        cout << b[q[front]] << "\n";
        while (front <= rear && a[q[front]] == i) {
            ++front;  
        }
    }
}