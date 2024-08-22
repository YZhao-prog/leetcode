#include <bits/stdc++.h>
using namespace std;

int n, m;
int len = 0;

int s1[100023];
int s2[100023];

struct Info {
    int v, pos;
} heap1[200010], heap2[200010];

void up1(int k) {
    while (k > 1 && heap1[k].v > heap1[k/2].v) {
        swap(heap1[k], heap1[k / 2]);
        s1[heap1[k].pos] = k;
        s1[heap1[k / 2].pos] = k / 2; 
        k = k / 2;
    }
}

void up2(int k) {
    while (k > 1 && heap2[k].v < heap2[k/2].v) {
        swap(heap2[k], heap2[k/2]);
        s2[heap2[k].pos] = k;
        s2[heap2[k / 2].pos] = k / 2;
        k = k / 2;
    }
}

void down1(int k) {
    while (k + k <= len) {
        int j = k + k;
        if (j + 1 <= len && heap1[j + 1].v > heap1[j].v) {
            j++;
        }
        if (heap1[k].v >= heap1[j].v) {
            break;
        }
        swap(heap1[k], heap1[j]);
        s1[heap1[j].pos] = j;
        s1[heap1[k].pos] = k;
        k = j;
    }
}

void down2(int k) {
    while (k + k <= len) {
        int j = k + k;
        if (j + 1 <= len && heap2[j + 1].v < heap2[j].v) {
            j++;
        }
        if (heap2[k].v <= heap2[j].v) {
            break;
        }
        swap(heap2[k], heap2[j]);
        s2[heap2[j].pos] = j;
        s2[heap2[k].pos] = k;
        k = j;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    len = n;

    for (int i = 1; i <= n; i++) {
        heap1[i].v = 100;
        heap2[i].v = 100;
        heap1[i].pos = i;
        heap2[i].pos = i;
        s1[i] = i;
        s2[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            heap1[s1[y]].v += z;
            heap2[s2[y]].v += z;
            up1(s1[y]);
            down1(s1[y]);
            up2(s2[y]);
            down2(s2[y]);
        }
        if (x == 2) {
            cout << heap1[1].v << " " << heap2[1].v << "\n";
        }
    }
}