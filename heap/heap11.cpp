#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n; i++) {
        cout << q.top() << " ";
        q.pop();
    }
}