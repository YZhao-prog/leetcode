#include <iostream>

using namespace std;

int n;
int heap[100001], len = 0;

void up(int k) {
    while (k != 1 && heap[k] < heap[k / 2]) {
        swap(heap[k], heap[k / 2]);
        k = k / 2;
    }
}

void down(int k) {
    while (k + k <= len) {
        int j = k + k;
        if (j + 1 <= len && heap[j + 1] <= heap[j]) {
            ++j;
        }
        if (heap[k] <= heap[j]) {
            break;
        }
        swap(heap[k], heap[j]);
        k = j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        heap[++len] = x;

        up(len);
    }

    for (int i = 0; i < n; i++) {
        cout << heap[1] << " ";
        swap(heap[1], heap[len]);
        len--;
        down(1);
    }
}