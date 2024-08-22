#include <bits/stdc++.h>
using namespace std;

int n, m;;
int k[20024], b[20024];

struct Info {
    int v, delta;
} heap[20001];


int len = 0;

void up(int k) {
    while (k != 1 && heap[k].v < heap[k / 2].v) {
        swap(heap[k], heap[k / 2]);
        k = k / 2;
    }
}

void down(int k) {
    while (k + k <= len) {
        int j = k + k;
        if (j + 1 <= len && heap[j + 1].v < heap[j].v) {
            j++;
        }
        if (heap[k].v <= heap[j].v) {
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
        int k, b;
        cin >> k >> b;
        heap[++len].v = b;
        heap[len].delta = k;
        up(len);
    }

    int m; 
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << heap[1].v << " ";
        heap[1].v += heap[1].delta;
        down(1);
    }
}