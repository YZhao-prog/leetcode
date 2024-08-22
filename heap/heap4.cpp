#include <bits/stdc++.h>
using namespace std;

priority_queue<int> heap1;
priority_queue<int, vector<int>, greater<int>> heap2;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    int x;
    cin >> x;
    heap1.push(x);
    cout << heap1.top() << " ";

    for (int i = 1; i <= n / 2; i++) {
        int x, y, z = heap1.top();
        cin >> x >> y;
        if (x <= z) {
            heap1.push(x);
        } else {
            heap2.push(x);
        }

        if (y <= z) {
            heap1.push(y);
        } else {
            heap2.push(y);
        }

        int a = heap1.size(), b = heap2.size();
        if (b - a == 1) {
            int tmp = heap2.top();
            heap2.pop();
            heap1.push(tmp);
        }

        if (a - b == 3) {
            int tmp = heap1.top();
            heap1.pop();
            heap2.push(tmp);
        }

        cout << heap1.top() << " ";
    }

}