#include <iostream>
using namespace std;

int q[100010];
int front = 1;
int rear = 0;
int m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;

    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;

        if (x == "push") {
            int y;
            cin >> y;
            q[++rear] = y; 
        }

        if (x == "query") {
            int y;
            cin >> y;

            int z = q[front + y - 1];
            cout << z << "\n";
        }

        if (x == "pop") {
            front++;
        }
    }

}