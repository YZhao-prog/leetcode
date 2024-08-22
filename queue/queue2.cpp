#include <iostream>

using namespace std;

int q[200010];
int front = 1;
int rear = 0;

int m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> k;

    int y = m;
    int z = 0;
    q[++rear] = y;
    for(int i = 0; i < k; i++) {
        int x = q[front];
        cout << x << "\n";
        front++;

        y = 2 * x;
        z = y + 1;
        q[++rear] = y;
        q[++rear] = z;
    }
}